#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class Solution {
    public:
        int rangeBitwiseAnd(int m, int n) {
#if 0
            while(n>m)
            {
                n=n&(n-1);
            }

            return n;
#endif
            //common left header
            int i = 0;
            while(m!=n){
                m=m>>1;
                n=n>>1;
                ++i;        
            }
            return m<<i;        
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->rangeBitwiseAnd(5,7) << endl;
    return 0;
}

