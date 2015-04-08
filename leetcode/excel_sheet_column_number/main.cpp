#include <iostream>
#include <cstdint>
#include <climits>
#include <stack>

using namespace std;

class Solution {
    public:
    int titleToNumber(string s) {
        int len = s.length();
        int ret = 0;
        for(int i=0; i<len; ++i)
            {
                    ret = 26*ret + (s[i] - 'A' + 1);
                    }
        
        return ret;
    }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->titleToNumber("AAB") <<endl;
    return 0;
}

