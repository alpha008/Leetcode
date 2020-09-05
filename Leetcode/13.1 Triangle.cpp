/**********************************************************************************************************
描述
Given a triangle, find the minimum path sum from top to boom. Each step you may move to adjacent
numbers on the row below.
For example, given the following triangle
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
e minimum path sum from top to boom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number
of rows in the triangle.      
**********************************************************************************************************/



class Solution{
public:
    int minimum(vector<vector<int>> & triangle){
        for(int i = triangle.size() - 2; i >=0; i--){
            for(int j = 0;j < triangle[i].size(); j++){
                triangle[i][j] = min(triangle[i + 1][j] , triangle[i + 1][j + 1]);
            }
        } 
        return triangle[0][0];
    }

};
















