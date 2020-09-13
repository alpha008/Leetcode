#include<stdio.h>
#include<string.h>

void printarray(int *data,int n )
{
    int i = 0;
    for(i = 0;i <n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
}
//内排序：不需要申请太多的空间
//外排序：与排序数量成正比


#define  DATA_ARRAY_LENGTH 12

//希尔排序， 分而治之
int shell_sort(int *data,int length){
    int gap = 0;
    int i = 0,j = 0;
    int temp = 0;
    int seq=0;
    for(gap = length/2; gap>=1;gap /=2){ //首先是次数
        for(i = gap;i <length;i++)
        {
            temp = data[i];
            for(j = i-gap;j >=0 && temp <data[j];j = j-gap)
            {//挖坑挨个和前面的比较，同时，下标是在变化的，直到不 < j  
                data[j+gap] = data[j]; //此时j已经挪到前面一个位置了
            }
            data[j+gap] = temp;//所以要在挪回去
        }
        printf("seq = %x,gap = %x\n",seq++,gap);
        printarray(data,DATA_ARRAY_LENGTH);
    }
}
void popsort(int *a, int n)
{
    int i =0, j = 0;

	for ( i = 0; i < n; i++)    //外层循环控制排序次数
	{      //i从0开始下面的才能比较到最后一个元素
		for ( j = 0; j < n - 1 - i; j++) //内层循环每排序一次就少一个数
		{     //如果前面的比后面的大，就前后交换顺序
			if (a[j]>a[j + 1])
			{
				int tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;  //相邻两个进行比较，然后向后移动
			}
		}
	}
}

void easy_sort(int *a, int n)
{
    int i = 0;
    int j = 0;
	for ( i = 0; i < n; i++)
	{//每个元素都有机会做比较
		int key = a[i];
		int index = i;
		for ( j = i+1; j < n; j++)
		{
			if (a[j] < key)
			{
				key = a[j];
				index = j;
			}
		}//寻找最小元素以及最小元素的下标
		int tmp = a[i];   //和哨兵交换顺序
		a[index] = tmp;
		a[i] = key;
	}
}

void insert_sort(int *a,int num)
{
	int i ,j ,key ;
	for ( i = 1; i < num; i++)
	{	
		int key = a[i];  //哨兵，数组取值都是挖空
		for ( j = i;j>0 && a[j-1] > key; j--) 
		{//挖空的前一个位置和key关键字比较
			a[j] = a[j-1]; //往后移动元素
		}
		a[j] = key;
	}
}

//归并排序          外排序
void merge(int *data,int *temp,int start,int middle,int end){
    int i = start, j = middle + 1,k = start;//k代表另一块空间
    while(i <= middle && j <=end) //[a]    [b]     将这个两个小数组变成有序的
    {
        if(data[i] > data[j]){
            temp[k++] = data[j++]; //取两者较小的放在中间数组中
        }else{
            temp[k++] = data[i++];
        }
    }
    while(i <= middle){       //当i和j两者中有一组比较完了，还有剩下的需要比较
        temp[k++] = data[i++];       
    }
    while(j <= end){
        temp[k++] = data[j++];       
    }
    for(i = start; i <=end;i ++){
        data[i] = temp[i];
    }
}

// 归并排序，需要外部存储空间来存储数据，这个很像是二叉树遍历的时候递归到底
// 然后合并回归
int merge_sort(int *data,int *temp,int start,int end){
    int middle;     //中间变量
    if(start < end)
    {
        middle = start + (end - start) / 2;
        merge_sort(data, temp, start, middle);//先分再治
        merge_sort(data, temp, middle +1, end);
        merge(data, temp, start,middle,end);
    }
}


//快速排序 -- 哨兵思维
void quick(int *data,int start,int end){
    if(start >= end) 
        return ; //停止条件

    int i = start;
    int j = end;
    int key = data[start];
    while(i < j){
        while(i < j && key <= data[j]){  //key   与i这个坑
            j--;
        }  
        data[i] = data[j];     //j这个坑去填前面i挖的坑
        while(i < j && key >= data[i]){  //key   与j这个坑
            i++;
        }
        data[j] = data[i]; //i这个坑去填后面j挖的坑
    }
    data[i] = key;         //执行完一轮后，左边比k小，右边比k大
    quick(data, start, i-1);
    quick(data, i + 1, end);
}

int  quick_sort(int *data,int length){
    quick(data, 0 ,length - 1);
    return 0;
}



int main(){
    int data[DATA_ARRAY_LENGTH] = {23,64,24, 12,9,16, 53,57,71, 79,87,97};
    int temp[DATA_ARRAY_LENGTH]={0};
    printarray(data,sizeof(data)/sizeof(int));
    quick_sort(data,DATA_ARRAY_LENGTH);
    //shell_sort(data,DATA_ARRAY_LENGTH );
    //merge_sort(data,temp,0,DATA_ARRAY_LENGTH-1);
    printarray(data,sizeof(data)/sizeof(int));
    return 0;
}