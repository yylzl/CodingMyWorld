#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int ret = 0;
            int i = 0;
            while(s[i])
            {
                if(s[i++]!=' ')
                {
                    ++ret;
                }
                else if(s[i] && (s[i] != ' '))
                {
                    ret = 0;
                }
            }
            return ret;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    string s = "abcd dfdfdf";
    cout << S->lengthOfLastWord(s) << endl;
    return 0;
}

