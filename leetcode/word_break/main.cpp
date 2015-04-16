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
        bool wordBreak(string s, unordered_set<string>& wordDict) {
            int n = s.length();
            bool dp[n+1];
            dp[0] = true;

            for(int i=1; i <= n; ++i)
            {
                dp[i] = false;
                //这里使用倒序速度更快
                //for(int j=i-1; j >=0; --j)
                //减少查找次数，因为dp[0]比为true
                for(int j=0; j < i; ++j)
                {
                    //使用wordDict.find(s.substr(j, i-j))速度更快
                    dp[i] |= (dp[j] && (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()));
                    if(dp[i])
                    {
                        break;
                    }
                }
            }

            return dp[n];
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    string s = "leetcode";
    unordered_set<string> wordDict;
    wordDict.insert("l");
    wordDict.insert("le");
    wordDict.insert("lee");
    wordDict.insert("ee");
    wordDict.insert("et");
    wordDict.insert("co");
    wordDict.insert("coo");
    wordDict.insert("cod");
    wordDict.insert("de");
    wordDict.insert("d");
    cout << S->wordBreak(s, wordDict) << endl;
    return 0;
}

