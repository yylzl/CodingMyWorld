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
        //refer http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-i.html for DP and expand solutions
        //Manacher's algorithm O(n) time extra O(n) space reference http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
        string longestPalindrome(string s) {
            int l = s.length();
            if(l==0)
            {
                return "";
            }
            if(l==1)
            {
                return s;
            }

            int i=0;
            string T="^#";
            for(i=0;i<l;++i)
            {
                T+=s[i];
                T+="#";
            }
            T+="$";
            //T  ^#a#b#c#b#a#$ ^and$ are sentinels
            int n = T.length();
            int P[n];
            cout << T << endl;
            int C=0, R=0;
            int mirror_i = 0;
            for(i=1;i<n-1;++i)
            {   
                mirror_i = 2*C - i;
                cout <<"C="<<C<<" R="<<R<<endl;
                cout <<"i="<<i<<" mirror_i="<<mirror_i<<endl;
                P[i] = (R > i) ? min(R-i, P[mirror_i]) : 0;

                while(T[i-1-P[i]]==T[i+1+P[i]])
                {
                    ++P[i];
                }

                if(P[i]+i > R)
                {
                    C=i;
                    R=P[i]+i;
                }
            }
            int max_len = 0;
            int center_idx = 0;
            for(i=1;i<n-1;++i)
            {
                cout << P[i] << endl;
                if(P[i] > max_len)
                {
                    max_len = P[i];
                    center_idx = i;
                }
            }
            cout <<"max_len="<< max_len <<" center_idx=" <<center_idx<<endl;
            return s.substr((center_idx-1-max_len)/2,max_len);
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->longestPalindrome("ababa") << endl;
    return 0;
}

