#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if(strs.empty())
            {
                return "";
            }
            vector<string>::iterator it0 = strs.begin();
            int i = (*it0).size();
            vector<string>::iterator it1 = it0+1;
            while((it1)!=strs.end())
            {
                cout << i << endl;
                if(i==0)
                {
                    return "";
                }
                if((*it1).size() < i)
                {
                    i = (*it1).size();
                }
                if((*it0).compare(0,i,*it1,0,i) == 0)
                {
                    ++it1;
                }
                else
                {
                    --i;
                }
            }

            return strs[0].substr(0,i);
        }        
};

int main(int argc, char *argv[])
{
    Solution *s = new Solution();
    vector<string> strs(2);
    strs[0] = "ab";
    strs[1] = "aa";
    cout << s->longestCommonPrefix(strs) << endl;
    return 0;
}

