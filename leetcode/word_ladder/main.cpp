#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        //好难 BFS搜索数 组成多叉树
        int ladderLength(string beginWord, string endWord, unordered_set<string> &wordDict) {
            if(beginWord=="" || beginWord.compare(endWord)==0)
            {
                return 0;
            }
            unordered_set<string>::iterator it;
            unordered_set<string> unique;
            queue<string> q;
            q.push(beginWord);
            q.push("");
            string str;
            int l = 1;
            while(!q.empty())
            {
                str = q.front();
                q.pop();
                if(str!="")
                {
                    for(int i=0;i<str.size();++i)
                    {
                        char tmp = str[i];
                        for(char c='a';c<='z';++c)
                        {
                            if(c==tmp)
                            {
                                continue;
                            }
                            str[i] = c;
                            cout<<str<<endl;
                            if(str==endWord)
                            {
                                return l+1;
                            }
                            if((wordDict.find(str)!=wordDict.end()) && (unique.find(str)==unique.end()))
                            {
                                q.push(str);
                                unique.insert(str);
                            }
                        }
                        str[i] = tmp;
                    }
                }
                else
                {
                    if(!q.empty())
                    {
                        q.push("");
                        ++l;
                    }
                }
            }
            return 0;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    unordered_set<string> str_set;
    str_set.insert("hot");
    str_set.insert("dot");
    str_set.insert("dog");
    str_set.insert("lot");
    str_set.insert("log");
    str_set.insert("cog");
    str_set.insert("hit");
    cout<< str_set.size() << endl;
    cout << S->ladderLength("hit", "cog", str_set) << endl;
    return 0;
}

