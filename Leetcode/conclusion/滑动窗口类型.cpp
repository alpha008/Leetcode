#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<deque>
using namespace std;
/***********************************************************************************************
1. Longest Substring Without Repeating Characters
2. 从给定字符串中找出包含目标串的最小子串
3.  滑动窗口的最大值
***********************************************************************************************/
void printvector(vector<int>&nums)
{
    cout<< "printvector: " ;
    for (auto i : nums)
	{
		cout << i << " " ;
	}
    cout << endl;
}
/***********************************************************************************************
1. Longest Substring Without Repeating Characters
给定一个字符串，求它的最长的不包含重复字符的子串的长度。也是一样的套模板。用HashSet记录是否有重复的字符，
从左往右扫描，不断更新最长长度。然后如果出现了重复，就把滑动窗口最左边那个字符从Set中去除，然后继续把滑动窗口往右移位。
//  是子串并非子序列
***********************************************************************************************/
 string lengthOfLongestSubstring(string s) {
        int length = 0, left = -1, n = s.size();
        int right = 0;
        unordered_map<int, int> m;  // 哈希表用来缓存数据，如果前面没有，那么放入集合中
        for ( right = 0; right < n; ++right) {
            // e[abcd]e  left = e  
            // 之前不管重复还是不重复都会缓存下来，但是目前缓存的内容不在窗口内，但是之前缓存过，因此会出现小于left的情况
            // 要将这种情况给剔除掉
            if (m.count(s[right]) && m[s[right]] > left) {  
                left = m[s[right]];  
            }
            m[s[right]] = right;   // 缓存数据
            length = max(length, right - left);            
        }
        return s.substr(left,length);
}
/**********************************************************************************************************
2. 从给定字符串中找出包含目标串的最小子串
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
For example, S = ”ADOBECODEBANC”, T = ”ABC”
Minimum window is ”BANC”.   这个题目不错，感觉挺好
**********************************************************************************************************/
string minWindow(string S, string T){
    cout << "S: " << S.size()<<endl;
    if(S.empty()) return "";
    if(S.size() < T.size()) return "";

    const int ASCII_MAX = 256;
    int appeared_count[ASCII_MAX];
    int expected_count[ASCII_MAX];
    fill(appeared_count, appeared_count + ASCII_MAX,0);
    fill(expected_count, expected_count + ASCII_MAX,0);

    for(size_t i = 0;i < T.size(); i++) 
        expected_count[T[i]]++;
    int minWidth = INT32_MAX, min_start = 0;
    int wnd_start = 0;
    int appeared = 0;
    for(size_t wnd_end = 0; wnd_end < S.size(); wnd_end ++){
        if(expected_count[S[wnd_end]] > 0){  // 说明所给字符在目标中存在
            appeared_count[S[wnd_end]]++; //统计出现的次数
            if(appeared_count[S[wnd_end]] <= expected_count[S[wnd_end]])
                appeared++;// 统计出现的个数，当其等于所给目标串的大小时，那么表示结果存在
        }// 当统计到的出现的个数 < 期望的时候，就++
        if(appeared == T.size()){
            while(appeared_count[S[wnd_start]] > expected_count[S[wnd_start]] || expected_count[S[wnd_start]] == 0 ){
                // 当统计到的次数 > 目标串中的次数时，起始位置就可以收缩   ||  或者从前往后过滤，当所给字符串在目标串中没有的时候也可以收缩
                // 统计的次数先 -1，然后窗口起始位置 +1
                cout <<"S[wnd_start] = " << S[wnd_start] << endl;
                appeared_count[S[wnd_start]]--;
                wnd_start++;
            }
            // 在这里更新窗口大小，取最小的值
            if(minWidth > (wnd_end - wnd_start + 1)){
                minWidth = wnd_end - wnd_start + 1;
                min_start = wnd_start;
            }
        }
    }
    if(minWidth == INT32_MAX ) 
        return "";
    else 
        return S.substr(min_start, minWidth);      
}
/**********************************************************************************************************
3. 滑动窗口的最大值
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
**********************************************************************************************************/
 //解法2：双向队列+滑动窗口
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(nums.empty()||k==0) 
        return {};
    vector<int> result;
    deque<int> window;//窗口，窗口保存数组的下标
    cout << window.size()<<endl;
    cout << window.empty()<<endl;
    for(int i = 0; i< k; ++i)
    {
        //窗口不为空并且下标i表示的元素大于window尾部下标表示的元素，删除尾部下标，保证窗口的头部为最大值
        while(!window.empty() && nums[i]>nums[window.back()])
            window.pop_back();
        window.push_back(i);//此时窗口的头部为最大值
    } 
    //将第一个窗口的最大值添加到result中
    result.push_back(nums[window.front()]);
    
    for(int i = k;i < nums.size(); ++i)
    {
        //1.窗口中队头的下标是否为上一个窗口的元素，如果是那么要删除
        if(!window.empty() && window.front() <= i-k)
            window.pop_front();
            
        //2.窗口不为空并且下标i表示的元素大于window尾部下标表示的元素，删除尾部下标，保证窗口的头部为最大值
        while(!window.empty() && nums[i]>nums[window.back()])
            window.pop_back();  
        window.push_back(i);
        //3.将结果更新到结果集中，如果不大于也要记录下来，但是始终保持头部最大
        result.push_back(nums[window.front()]);//将窗口的最大值添加到result中
    }
    
    return result;
}

int main()
{
    vector<int> result;
    string str1 = "pwwkew";
    //1.单个字符内，最长的不包含重复字符的子串的长度
    cout << "lengthOfLongestSubstring: " << lengthOfLongestSubstring(str1) << endl;
    //2. 
    string str2 = "ADOBECODEBANC";
    string target = "ABC";
    cout << "minWindow :" << minWindow(str2,target) << endl;
    //3.
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    result = maxSlidingWindow(nums,3);
    cout << "maxSlidingWindow:" << endl;
    printvector(result);

    return 0;
}
