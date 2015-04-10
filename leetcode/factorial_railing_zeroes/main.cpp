#include <iostream>
#include <cstdint>
#include <climits>

using namespace std;

/*
 * [1...n]内能被5整除的数的个数为n/5
 * 25算2个5即n/5/5，125,625...
 * 结尾的0都来自2x5,2的个数肯定多于5的个数
 * n/2 > n/5
 * */

class Solution {
    public:
        int trailingZeroes(int n) {
            int ret = 0;
            while(n)
            {
                ret += n/5;
                n/=5;
            }
            return ret;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->trailingZeroes(123) << endl;
    return 0;
}

