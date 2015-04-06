#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
#if 1
            string ans("1");
            if (n == 1)
                return ans;

            while (--n) {
                string temp = ans;
                ans.clear();
                int count = 1;
                for (int i = 0; i < temp.size(); i++) {
                    if (temp[i] == temp[i + 1])
                        count++;
                    else {
                        ans.push_back(count + '0');
                        ans.push_back(temp[i]);
                        count = 1;
                    }
                }
            }
            return ans;
#else
            if(n==1)
            {
                return string("1");
            }
            else
            {
                string pre = countAndSay(n-1);
                stringstream ss;
                string s;
                int len = pre.length();
                int i = 0;
                int c = 1;
#if 0
                for(i=1;i<len;++i)
                {
                    if(pre[i]==pre[i-1])
                    {
                        c++;
                    }
                    else
                    {
                        ss << c << pre[i-1];
                        c = 1;
                    }
                }
                ss << c << pre[i-1];
#else
                for(i=0;i<len;++i)
                {
                    if(pre[i]==pre[i+1])
                    {
                        c++;
                    }
                    else
                    {
                        ss << c << pre[i];
                        c = 1;
                    }
                }
#endif
                ss >> s;
                return s;
                cout <<len <<" " << pre << endl;
                cout << s << endl;
            }
#endif
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->countAndSay(5) << endl;
    return 0;
}

