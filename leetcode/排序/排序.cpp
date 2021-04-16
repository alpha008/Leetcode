#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
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


#include<algorithm>


class Solution {
public:
//希尔排序， 分而治之
int shell_sort(vector<int>nums){
    int length =  nums.size();
    int gap = 0;
    int i = 0,j = 0;
    int key = 0;
    for(gap = length/2; gap >=1 ; gap /=2){ //首先是次数
        for(i = gap;i < length; i++)
        {
            key = nums[i];
            for(j = i - gap;j >=0 && key < nums[j];j = j - gap)
            {
                nums[j + gap] = nums[j];
            }
            nums[j + gap] = key;
        }
    }
}

// 冒泡排序
    void popsort(vector<int> nums)
    {
        int i = 0, j = 0;
        int n = nums.size();
        for ( i = 0; i < n - 1; i++)    
        { 
            for ( j = 0; j < n - 1 - i; j++)  // 每循环一次，外循环就可以少循环一次
            {   
                if (nums[j]>nums[j + 1])
                {
                    swap(nums[j],nums[j + 1]);
                }
            }
        }
    }
     vector<int> sortArray(vector<int>& nums) {
        /*快速排序
        int start = 0, end = nums.size() - 1;
        quick(nums, start , end);
        return nums;**/
        /*2. 归并排序*/
        vector<int>temp(nums.size(), 0);
        merge_sort(nums, temp, 0, nums.size()-1);
        return nums;
    }
// 归并排序
    void merge_sort(vector<int>&nums, vector<int>& temp, int start, int end){
        int middle;
        if(start >= end)
            return ;
        middle = start + (end - start ) /2;
        merge_sort(nums, temp, start ,middle);
        merge_sort(nums, temp , middle+1, end);
        merge(nums, temp, start, middle, end);   
    }
    void merge(vector<int>&nums, vector<int>& temp, int start, int middle, int end){
        int i = start , j = middle + 1, k = start;
        while(i <= middle && j <= end){
            if(nums[i] > nums[j]){
                temp[k++] = nums[j++];
            }else{
                temp[k++] = nums[i++];
            }
        }
        while(i <= middle ){
            temp[k++] = nums[i++];
        }
        while(j <= end){
            temp[k++] = nums[j++];
        }
        for(i = start; i <= end; i++){
            nums[i] = temp[i];
        }
    }
//快速排序
     vector<int> sortArray(vector<int>& nums) {
       //快速排序
        int start = 0, end = nums.size() - 1;
        quick(nums, start , end);
        return nums;
    }
    void quick(vector<int>&nums, int start , int end){
        if(start >= end)
            return ;
        int i = start;
        int j = end;
        int key = nums[start];
        while(i < j){
            while(i < j && key <= nums[j])
            {
                j--;
            }
            nums[i] = nums[j];
            while(i < j && key >= nums[i])
            {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = key;
        quick(nums, start , i - 1);
        quick(nums, i + 1,  end );    
    }
    // 插入排序
    void insert_sort(vector<int>nums)
    {//key前面是有序的
        int i ,j ,key ;
        int num = nums.size();
        for ( i = 1; i < num; i++)
        {	
            int key = nums[i];  //循环到谁就把谁拿出来当key
            for ( j = i; j > 0 &&  key < nums[j-1] ; j--) 
            {//挖空的前一个位置和key关键字比较
                nums[j] = nums[j-1]; //往后移动元素
            }
            nums[j] = key;//前面的都比key小，那么j位置就留给key
        }
    }
//简单排序
    void easy_sort(vector<int>nums)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        for ( i = 0; i < n; i++)
        {
            int key = nums[i];
            int index = i;       
            for ( j = i + 1; j < n; j++)
            {
                if (nums[j] < key)
                {
                    key = nums[j];
                    index = j;
                }
            }// 寻找最小元素记录下标
            int tmp = nums[i];  
            nums[index] = tmp;
            nums[i] = key; //找到最小的与哨兵元素交换
        }
    }
};
//41. First Missing Positive --hard 
//[1 2 3 4 5 6 7 8 9 ]  value
// 0 1 2 3 4 5 6 7 8    index 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bucket_sort(nums, n);
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1)
                return i + 1;            
        }
        return  n+1;
    }
    void bucket_sort(vector<int> &nums, int n){
        for(int i = 0; i < n ; i++){
            while(nums[i] != i + 1){
                if(nums[i] <=0 || nums[i] > n || nums[i] == nums[nums[i] - 1])
                    break;
                swap(nums[i], nums[nums[i] - 1]);  
                // nums[i] 应该在nums[i] - 1 这个位置上,一直更换到不满足条件位置
            }
        }
    } 
};
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





