#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint8_t i = 0;
            uint32_t ret = 0;
            for(i=0;i<32;++i)
            {
                ret |= ((n>>i)&1)<<(31-i);
            }
            return ret;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->reverseBits(43261596) << endl;
    return 0;
}

