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
1. Longest Substring Without Repeating Characters --hard
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
//76. Minimum Window Substring  -- hard
//For example, S = ”ADOBECODEBANC”, T = ”ABC”
/***********************************************************************
expected_count[A] = 1 ;expected_count[B] = 1 ;expected_count[C] = 1
expected_count[] = ?  ;expected_count[] = ? ;expected_count[] = ? ;
************************************************************************/
string minWindow(string s, string t){
    if(s.empty()) return "";
    if(s.size() < t.size()) return "";

    const int ASCII_MAX = 256;
    int appeared_count[ASCII_MAX];
    int expected_count[ASCII_MAX];
    fill(appeared_count, appeared_count + ASCII_MAX,0);
    fill(expected_count, expected_count + ASCII_MAX,0);

    for(size_t i = 0;i < t.size(); i++) 
        expected_count[t[i]]++;
    int minWidth = INT32_MAX, min_start = 0;
    int wnd_start = 0;
    int appeared = 0;
    for(size_t wnd_end = 0; wnd_end < s.size(); wnd_end ++){
        if(expected_count[s[wnd_end]] > 0){ 
            appeared_count[s[wnd_end]]++; // 只要出现了就统计
            if(appeared_count[s[wnd_end]] <= expected_count[s[wnd_end]])
                appeared++;
        } // 统计 target出现且自己也统计到的
        if(appeared == t.size()){ // 说明全都出现了
            while(appeared_count[s[wnd_start]] >  expected_count[s[wnd_start]] 
            || expected_count[s[wnd_start]] == 0 ){
                wnd_start++; //当开始字母出现多次或者没有出现那么就可以收缩窗口
                appeared_count[s[wnd_start]]--;
            }    
            if(minWidth > (wnd_end - wnd_start + 1)){  // 在这里更新窗口大小，取最小的值
                minWidth = wnd_end - wnd_start + 1;
                min_start = wnd_start;
            }
        }
    }
    if(minWidth == INT32_MAX ) 
        return "";
    else 
        return s.substr(min_start, minWidth);      
}

//239. Sliding Window Maximum -- hard
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(nums.size() == 0)
        return nums;
    vector<int> result;
    deque<int> window;
    for(int i = 0; i < nums.size(); i++)
    {
        while(!window.empty() && nums[i] > nums[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);  //将自己加入队列要排名次

        if(!window.empty() && window.front() <= (i - k))   // 删除上一个窗口的
            window.pop_front();

        if(i >= k - 1)  //主要是为了约束刚开始k个元素组成的窗口
            result.push_back(nums[window.front()]);
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
