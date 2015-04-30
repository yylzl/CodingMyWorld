#include <iostream>
#include <cstdint>
#include <climits>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            char s2t[256] = {0};
            char t2s[256] = {0};
            for(int i=0;i<s.size();++i)
            {
                if(s2t[s[i]]==0)
                {
                    s2t[s[i]] = t[i];
                }
                else
                {
                    if(s2t[s[i]] != t[i])
                    {
                        return false;
                    }
                }

                if(t2s[t[i]]==0)
                {
                    t2s[t[i]] = s[i];
                }
                else
                {
                    if(t2s[t[i]]!=s[i])
                    {
                        return false;
                    }
                }
            }

            return true;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->isIsomorphic("eaa", "gmm") << endl;
    return 0;
}

