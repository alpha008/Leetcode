
/**********************************************************************************************************
Given an array and a value, remove all instances of that value in place and return the new length.
e order of elements can be changed. It doesn’t matter what you leave beyond the new length.


**********************************************************************************************************/



#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
    int removeElement(int A[],int n,int elem){
        int index = 0;
        for(int i = 0 ;i < n;i++){
            if(A[i] != elem){
                A[index++] = A[i];
            }
        }
        return index;
    }

}

