牛客网题目：
1.数组中重复的数字
2.构建乘机数组




1.数组中重复的数字
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        map<int,int> map1;
        for(int i = 0; i < length; i++)
        {
            if(map1.count(numbers[i]) == 1){
                *duplication = numbers[i];
                return true;
            }
            else{
               map1[numbers[i]]++;
            } 
        }
        return false;
    }
};
2.构建乘机数组
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
         vector<int>B;
        for(int i = 0;i<A.size();i++){
            int sum = 1;
            for(int j = 0; j < i;j++){
                sum = sum *A[j];
            }
            for(int j = i + 1; j < A.size();j++){
                sum  = sum *A[j];
            }
            B.push_back(sum);
        }
        return B;
    }
};