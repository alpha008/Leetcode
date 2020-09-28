
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#define LL_ADD(item, list) do {				\
	item->prev = NULL;						\
	item->next = list;						\
	if (list != NULL) list->prev = item;	\
	list = item;							\	
} while (0)
#define LL_REMOVE(item, list) do {			\
	if (item->prev != NULL) item->prev->next = item->next;	\
	if (item->next != NULL) item->next->prev = item->prev;	\
	if (list == item) list = item->next;					\
	item->prev = item->next = NULL;							\
} while (0)
typedef struct NWORKER {
	pthread_t threadid;
	int terminate;
	struct NMANAGER *pool;
	struct NWORKER *next;
	struct NWORKER *prev;
} nWorker;
typedef struct NJOB {
	void (*func)(void *arg);
	void *user_data;
	struct NJOB *next;
	struct NJOB *prev;
} nJob;
typedef struct NMANAGER {
	nWorker *workers;
	nJob *jobs;
	int sum_thread;
	int free_thread; //free_thread = sum_thread;
	pthread_mutex_t jobs_mtx;
	pthread_cond_t jobs_cond;
} nManager;

typedef nManager nThreadPool;
void *nWorkerCallback(void *arg) {
	nWorker *worker = (nWorker*)arg;
	while (1) {
		// jobs != null
		pthread_mutex_lock(&worker->pool->jobs_mtx);
		while (worker->pool->jobs == NULL) {
			if (worker->terminate == 1) break;
			pthread_cond_wait(&worker->pool->jobs_cond, &worker->pool->jobs_mtx);
		}
		if (worker->terminate == 1) { 
			pthread_mutex_unlock(&worker->pool->jobs_mtx);
			break;
		}
		// ll_remove(item, jobs)
		nJob *job = worker->pool->jobs;
		LL_REMOVE(job, worker->pool->jobs);	
		pthread_mutex_unlock(&worker->pool->jobs_mtx);
		// enter 
		worker->pool->free_thread --;		
		job->func(job->user_data);
		// end
		worker->pool->free_thread ++;		
		free(job);
		// jobs->func(jobs);
	}

	free(worker);

}

int nThreadPoolCreate(nThreadPool *pool, int numWorkers) {

	if (pool == NULL) return -1;
	if (numWorkers < 1) numWorkers = 1;
	memset(pool, 0, sizeof(nThreadPool));


	pthread_mutex_t blank_mutex = PTHREAD_MUTEX_INITIALIZER;
	memcpy(&pool->jobs_mtx, &blank_mutex, sizeof(pthread_mutex_t));

	pthread_cond_t blank_cond = PTHREAD_COND_INITIALIZER;
	memcpy(&pool->jobs_cond, &blank_cond, sizeof(pthread_cond_t));

	int i = 0;
	for (i = 0;i < numWorkers;i ++) {

		nWorker *worker = (nWorker*)malloc(sizeof(nWorker));
		if (worker == NULL) {
			perror("malloc");
			return 1;
		}
		memset(worker, 0, sizeof(nWorker));
		
		int ret = pthread_create(&worker->threadid, NULL, nWorkerCallback, worker);
		if (ret) {
			perror("pthread_create");
			//free(worker);
			nWorker *w = pool->workers;
			for (w = pool->workers; w != NULL; w = w->next) {
				w->terminate = 1;
			}
				
			return 1;
		}
		LL_ADD(worker, pool->workers);
	}

	return 0;
}
int nThreadPoolDestory(nThreadPool *pool) {
	nWorker *w = pool->workers;
	for (w = pool->workers; w != NULL; w = w->next) {
		w->terminate = 1;
	}
	pthread_mutex_lock(&pool->jobs_mtx);
	pthread_cond_broadcast(&pool->jobs_cond);
	pthread_mutex_unlock(&pool->jobs_mtx);
}
int nThreadPoolPushJob(nThreadPool *pool, nJob *job) {

	pthread_mutex_lock(&pool->jobs_mtx);
	LL_ADD(job, pool->jobs);

	pthread_cond_signal(&pool->jobs_cond);
	pthread_mutex_unlock(&pool->jobs_mtx);

}
// API
// int nThreadPoolCreate(nThreadPool *pool, int numWorkers) 
// int nThreadPoolPushJob(nThreadPool *pool, nJob *job)
// int nThreadPoolDestory(nThreadPool *pool)