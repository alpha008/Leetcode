#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        int retValue = -1;
        unordered_map<int, list<pair<int, int> > ::iterator> ::iterator it = cachesMap.find(key);
        //如果在Cacah中，将记录移动到链表的最前端
        if (it != cachesMap.end())
        {
            retValue = it->second->second;
            //移动到最前端
            list<pair<int, int> > ::iterator ptrPair = it->second;
            pair<int, int> tmpPair = *ptrPair;
            caches.erase(ptrPair++);
            caches.push_front(tmpPair);
            //修改map中的值
            cachesMap[key] = caches.begin();
        }
        return retValue;
    }
    void set(int key, int value) {

        unordered_map<int, list<pair<int, int> > ::iterator> ::iterator it = cachesMap.find(key);
        if (it != cachesMap.end()) //已经存在其中
        {
            list<pair<int, int> > ::iterator ptrPait = it->second;
            ptrPait->second = value;
            pair<int, int > tmpPair = *ptrPait;
            caches.erase(ptrPait);                         //移动到最前面
            caches.push_front(tmpPair);
            //更新map
            cachesMap[key] = caches.begin();  //将双链表的位置记录到cachesMap此处
        }
        else //不存在其中
        {
            pair<int, int > tmpPair = make_pair(key, value);
            if (m_capacity == caches.size()) //已经满
            {
                int delKey = caches.back().first;
                caches.pop_back(); //删除最后一个，删除在map中的相应项
                unordered_map<int, list<pair<int, int> > ::iterator> ::iterator delIt = cachesMap.find(delKey);
                cachesMap.erase(delIt++);
            }
            caches.push_front(tmpPair);
            cachesMap[key] = caches.begin(); //更新map
        }
    }
private:
    int m_capacity;                                                                        //cashe的大小
    list<pair<int, int> > caches;                                                  //用一个双链表存储cashe的内容
    unordered_map< int, list<pair<int, int> > ::iterator> cachesMap;         //使用map加快查找的速度
};


int main(int argc, char **argv)
{
    LRUCache s(2);
    s.set(2, 1);
    s.set(1, 1);
    cout << s.get(2) << endl;
    s.set(4, 1);
    s.set(5, 2);
    cout << s.get(5) << endl;
    cout << s.get(4) << endl;
    getchar();
    return 0;
}