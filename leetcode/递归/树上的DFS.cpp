/**************************************************************************************************

 *************************************************************************************************/

/**********************************************************************************************************
当题目看不出任何规律，既不能用分治，贪心，也不能用动规时，这时候万能方法——搜就
派上用场了。搜索分为广搜和深搜，广搜里面又有普通广搜，双向广搜， A* 搜索等。深搜里面又有普通深搜，回溯法等。
广搜和深搜非常类似（除了在扩展节点这部分不一样），二者有相同的框架，如何表示状
如何扩展状态？如何判重？尤其是判重，解决了这个问题，基本上整个问题就解决了。


描述
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence
from start to end, such that:
• Only one leer can be changed at a time
• Each intermediate word must exist in the dictionary
For example, Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is ”hit” -> ”hot” -> ”dot” -> ”dog” -> ”cog”, return its length 5.
Note:
• Return 0 if there is no such transformation sequence.
• All words have the same length.
• All words contain only lowercase alphabetic characters.

**********************************************************************************************************/
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


/**********************************************************************************************************
9.2 Word Ladder II
描述
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from
start to end, such that:
• Only one leer can be changed at a time
• Each intermediate word must exist in the dictionary
For example, Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:
• All words have the same length.
• All words contain only lowercase alphabetic characters.
分析
跟 Word Ladder 比，这题是求路径本身，不是路径长度，也是 BFS，略微麻烦点。
这题跟普通的广搜有很大的不同，就是要输出所有路径，因此在记录前驱和判重地方与普广搜略有不同
**********************************************************************************************************/

class Solution{
public:
    vector<vector<sting>> findLadders(string start, string end,const unordered_set<string> &dict){
        unorder_set<string> visited; //判重
        unorder_map<string, vector<string>> father;
        unorder_set<string> current, next;
        bool found = false;
        current.insert(start);

        while(!current.empty() && !found){
           for(auto word : current){
                visited.insert(word); //先将本层全部置为已访问，防止同层之间互相指向
           } 
           for(auto word : current){
                for(size_t i = 0; i < word.size(); i ++){
                    string new_word = word;
                    for(char c = 'a';c < 'z';c ++){
                        if(c == new_word[i]) contuine;
                        swap(c, new_word[i]);

                        if(new_word == end()) found = true;

                        if(visited.count(new_word) == 0 && (dict.count(new_word)> 0)||
                            new_word ==  end){
                            next.insert(new_word);
                            father[new_word].push_back(word);
                        }
                        swap(c ,new_word[i]);//restore
                    }
                }
           }
           current.clear();
           swap(current, next);
        }
        vector<vector<string>> result;
        if(found){
            vector<string> path;
            bulidPath(father, path, start, end , result);
        }
        return result;
    }
private:
    void bulidPath(unordered_map<string, vector<string>> &father,vecotr<string> &path,const string &start,
        const string &end , vector<vector<string>> &result){
            path.push_back(word);
            if(word == start){
                result.push_back(path);
                reverse(result.back().begin(), result.back().end());
            }
            else{
                for(auto f : father[word]){
                    bulidPath(father, path, f, result);
                }
            }
            path.pop_back();
        }
        
};


