#include <iostream>
#include <cstdint>
#include <climits>
#include <stack>

using namespace std;

class Solution {
    public:
        string convertToTitle(int n) {
            string ret;
            char c;
            while(n)
            {
                --n;
                c = (n%26)+'A';
                ret = c + ret;
                n/=26;
            }
            return ret;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->convertToTitle(52) <<endl;
    return 0;
}

