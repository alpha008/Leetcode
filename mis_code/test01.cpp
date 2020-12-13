#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;
#if 0
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end()); // 必须排序
		vector<vector<int> > result;
		vector<int> path;
		dfs(S, S.begin(), path, result);
		return result;
	}
private:
	static void dfs(const vector<int> &S, vector<int>::iterator start,
		vector<int> &path, vector<vector<int>> &result) {
		result.push_back(path);
		for (auto i = start; i < S.end(); i++) {
			if (i != start && *i == *(i - 1)) continue;
			path.push_back(*i);
			dfs(S, i + 1, path, result);
			path.pop_back();
		}
	}
};
int main()
{
	vector<int >vec = { 1, 2, 3 };
	Solution ss;
	ss.subsetsWithDup(vec);
	return 0;
}
#else 
class Solution{
public:
	typedef string state_t;
	int ladderLength(string start, string end, const unordered_set<string> &dict){
		if (start.size() != end.size()) return 0;
		if (start.empty() || end.empty()) return 0;

		queue<string > next, current;// 下一层 ，当前层
		unordered_set<string> visited; //判断重复
		int level = 0;
		unordered_map<string, string> father;
		bool found = false;
		current.push(start);

		while (!current.empty() && !found){
			++level;
			while (!current.empty() && !found){
				const string str(current.front());
				current.pop();
				for (size_t i = 0; i < str.size(); i++){
					string new_word(str);
					for (char c = 'a'; c < 'z'; c++){ //start = "hit"
						if (c == new_word[i]) continue;
						swap(c, new_word[i]);
						if (new_word == end){
							found = true;
							father[new_word] = str;//??
						}
						if (dict.count(new_word) > 0 && !visited.count(new_word)){
							next.push(new_word);
							visited.insert(new_word);
							father[new_word] = str;
						}
						swap(c, new_word[i]);
					}
				}
			}
			swap(next, current);
		}
		if (found) return level + 1;
		else return 0;
	}
};

int main1()
{
	unordered_set<string> words{ "hot", "dot", "dog", "lot", "log" };// Initializer list
	Solution ss;
	ss.ladderLength("hit", "cog", words);
	return 0;
}
#endif