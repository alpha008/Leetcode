#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
    //int array[] = {2,1,5,3,6,4,8,9,7};
    int array[] = {1,12,13,15,18};
   // search(array,sizeof(array)/sizeof(int),14);
   二分法查找的时候，查找目标值，在数组中的左边界
*/
void search(int *array,int n,int target)
{
    int l = 0,r = n - 1,m = 0;

        while( l <= r)
        {
            m = (l + r) /2;
            if(target > array[m]){
               l = m + 1;  // 左边第一个>
            }else{
               r = m - 1; 
            }
        }
        cout << "l = "<< l << "r = " << r << endl;
}
vector<vector<int>> getdp(string s1,string s2)
{
     vector<vector<int>> dp;


}
int main(){

    //int array[] = {2,1,5,3,6,4,8,9,7};
    int array[] = {1,12,13,15,18};
    search(array,sizeof(array)/sizeof(int),14);
   // search(array,sizeof(array)/sizeof(int),19);
    return 0;
}