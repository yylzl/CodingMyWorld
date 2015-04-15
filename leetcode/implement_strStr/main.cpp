#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class Solution {
    public:
        //"" "" return 0
        //"adfb" "" return 0
        //提前返回的条件如果haystack的剩余长度小于needle就不用再继续比较下去了
        //Rabin-Karp algorithm, KMP algorithm, and the Boyer- Moore algorithm成熟算法
        int strStr(string haystack, string needle) {
#if 0
            if((needle.size() == 0) && (haystack.size() == 0))
            {
                return 0;
            }
            else
            {
                if(haystack.size() == 0)
                    return -1;
                if(needle.size() == 0)
                    return 0;
                if(needle.size() > haystack.size())
                {
                    return -1;
                }
                for(int i = 0; haystack.size() - i >= needle.size(); ++i)
                {
                    if(haystack.compare(i, needle.size(),needle)==0)
                    {
                        return i;
                    }

                }        
                return -1;
            }
#endif
            for (int i = 0; ; ++i) {
                for (int j = 0; ; ++j) {
                    if (needle[j] == 0) return i;
                    if (haystack[i + j] == 0) return -1;
                    if (haystack[i + j] != needle[j]) break;
                }
            }            
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    string haystack = "adfdafdfdfdf";
    string needle = "dfdf";
    cout << S->strStr(haystack, needle) << endl;
    return 0;
}

