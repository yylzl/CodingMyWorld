#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        //统计每个10个字符序列出现的次数，使用hash表
        //A C G T10个字符用一个int表示其哈希值
        //第二种方法使用stl hash函数
        vector<string> findRepeatedDnaSequences(string s) {
#if 0
            unordered_map<int, int> m;
            vector<string> r;
            int t = 0, i = 0, ss = s.size();
            while (i < 9)
                t = t << 3 | s[i++] & 7;
            while (i < ss)
                if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
                    r.push_back(s.substr(i - 10, 10));
            return r;     
#endif
            vector<string> ret;
            if(s.size()<10)
            {
                return ret;
            }
            unordered_map<int, bool> m;
            string tmp;
            hash<string> h_f;
            int h;
            for(int i=0;i<=s.size()-10;++i)
            {
                tmp = s.substr(i,10);
                h = h_f(tmp);
                if(m.find(h)==m.end())
                {
                    m[h] = false;
                }
                else
                {
                    if(m[h]==false)
                    {
                        ret.push_back(tmp);
                        m[h] = true;
                    }
                }
            }

            return ret;               
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ret = S->findRepeatedDnaSequences(str);
    vector<string>::iterator it;
    for(it=ret.begin();it!=ret.end();++it)
    {
        cout<<*it<<endl;
    }
    return 0;
}

