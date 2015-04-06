#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int ret = 0;
            while(n)
            {
                n=n&(n-1);
                ++ret;
            }
            return ret;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution;
    cout << S->hammingWeight(25) << endl;
    return 0;
}

