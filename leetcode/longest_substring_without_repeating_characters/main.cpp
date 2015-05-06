#include <iostream>
#include <cstdint>
#include <climits>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int max_len = 0;
            int start = 0;
            int end = 0;
            int m[256] = {0};

            while(end<s.size())
            {
                //cout<<m[s[end]]<<endl;
                if(m[s[end]] <= start)
                {
                    m[s[end]] = end+1;
                    ++end;
                }
                else
                {
                    if((end-start) > max_len)
                    {
                        max_len = end-start;
                    }
                    start = m[s[end]];
                    if(max_len >= s.size()-start)
                    {
                        return max_len;
                    }                    
                }
            }

            if((end-start) > max_len)
            {
                max_len = end-start;
            }

            return max_len;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->lengthOfLongestSubstring("abcabcbb")<<endl;
    //cout << S->lengthOfLongestSubstring("c")<<endl;
    return 0;
}

