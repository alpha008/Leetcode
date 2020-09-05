/**********************************************************************************************************
Given an array of integers, every element appears twice except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using
extra memory? 
**********************************************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
public:
    int singleNumber(int A[], int n ){
        int x = A[0];
        for(int i = 1;i < n;i ++){
            x ^= A[i];
        }
        return x;
    }

};


class Solution{
    int singleNumber(int A [ ], int n,int k){
        const int W = sizeof(int) * 8;
        int count[W];
        fill_n(&count[0], W, 0);
        for(int i = 0;i  < n; i++){
            for(int j = 0;j < W; j++){
                count[j] += (A[i] >> j) & 1;
                count[j] % = k;//统计出现k次的
            }
        }
        int result = 0;
        for(int i = 0;i < W;i++){
            result +=(count[i] << i);
        }
        return result;
    }

};

