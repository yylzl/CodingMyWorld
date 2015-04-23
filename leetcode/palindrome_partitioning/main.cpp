#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s, int start, int end) {
            while(start < end)
            {
                if(s[start]==s[end])
                {
                    ++start;
                    --end;
                }
                else
                {
                    return false;
                }
            }

            return true;
        }        
        void findpartition(string s, int start, vector<vector<string> > &r, vector<string> one) {
            if(start==s.size())
            {
                r.push_back(one);
            }
            for(int i=start;i<s.size();++i)
            {
                if(isPalindrome(s, start, i))
                {
                    one.push_back(s.substr(start,i-start+1));
                    findpartition(s, i+1, r, one);
                    one.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<vector<string> > ret;
            if(s=="")
                return ret;
            vector<string> one;
            findpartition(s, 0, ret, one);
            return ret;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    vector<vector<string> > ret;
    ret = S->partition("aabaadcb");
    vector<vector<string> >::iterator it1;
    vector<string>::iterator it2;
    for(it1=ret.begin();it1!=ret.end();++it1)
    {
        for(it2=(*it1).begin();it2!=(*it1).end();++it2)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}

