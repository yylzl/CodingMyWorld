#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        //backtrace 回溯法  提前结束条件 回溯
        //提前结束是否是有效ip 小于256 开头是0 的只有0有效 其它010 00 01都无效
        //回溯 r = r.substr(0,r.length()-i-1);继续下一次寻找
        void restoreIpAddresses(vector<string> &v, string s, int pos, int dot, string r)
        {
            //cout <<"pos="<<pos<<" r="<<r<<" dot="<<dot<<endl;
            
            if(dot==4)
            {
                if((s.length() <= pos) || (s.length() - pos > 3)) 
                    return;
                string sub = s.substr(pos);
                if((sub[0] == '0') && (sub.length() > 1))
                {
                    return;
                }
                if(stoi(sub) < 256)
                {
                    r += sub;
                    v.push_back(r);
                }
                return;
            }
            for(int i=1;i<4;++i)
            {
                if((s.length() <= pos + i))
                {
                    return;
                }
                string sub = s.substr(pos, i);
                if((sub[0] == '0') && (sub.length() > 1))
                {
                    return;
                }
                if(stoi(sub) < 256)
                {
                    r += sub;
                    r += ".";
                    restoreIpAddresses(v, s, pos+i, dot+1, r);
                    r = r.substr(0,r.length()-i-1);
                }
            }
        }
        vector<string> restoreIpAddresses(string s) {
            vector<string> ret;
            int len = s.length();
            if(len < 4)
                return ret;
            if(len > 12)
                return ret;

            string r="";
            restoreIpAddresses(ret, s, 0, 1, r);
            return ret;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    string s = "010010";

    vector<string> ret = S->restoreIpAddresses(s);
    vector<string>::iterator it;
    for(it=ret.begin();it!=ret.end();++it)
    {
        cout << *it << endl;
    }
    return 0;
}

