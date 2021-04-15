



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#define ALLOC_SIZE 512

typedef int KEY_TYPE;

typedef struct _queue_node {

	struct _queue_node *next;
	KEY_TYPE key;

} queue_node;

typedef struct _queue {

	queue_node *front;
	queue_node *rear;

	int queue_size;
	
} queue;

void init_queue(queue *q) {

	q->front = q->rear = NULL;
	q->queue_size = 0;
}

void destory_queue(queue *q) {

	queue_node *iter;
	queue_node *next;

	iter = q->front;

	while (iter) {
		next = iter->next;
		
		free(iter);
		iter = next;
	}
	
}

void push_queue(queue *q, KEY_TYPE key) {

	assert(q);

	if (q->rear) {

		queue_node *node = (queue_node*)calloc(1, sizeof(queue_node));
		assert(node);

		node->key = key;
		node->next = NULL;

		q->rear->next = node;
		q->rear = node;
		
	} else {

		queue_node *node = (queue_node*)calloc(1, sizeof(queue_node));
		assert(node);

		node->key = key;
		node->next = NULL;

		q->front = q->rear = node;
		
	}
	q->queue_size ++;
}

void pop_queue(queue *q, KEY_TYPE *key) {

	assert(q);
	assert(q->front != NULL);

	if (q->front == q->rear) {
		*key = q->front->key;

		free(q->front);
		q->front = q->rear = NULL;
	} else {

		queue_node *node = q->front->next;

		*key = q->front->key;
		free(q->front);

		q->front = node;

	}
	q->queue_size --;
}

int empty_queue(queue *q) {

	assert(q);

	return q->rear == NULL ? 0 : 1;

}

int size_queue(queue *q) {

	return q->queue_size;

}

int main() {

	queue q;

	init_queue(&q);

	int i = 0;
	for (i = 0;i < 1000;i ++) {
		push_queue(&q, i+1);
	}

	while (empty_queue(&q)) {

		KEY_TYPE key;
		pop_queue(&q, &key);

		printf("%4d", key);
		
	}

	destory_queue(&q);

}



