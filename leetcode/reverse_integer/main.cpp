#include <iostream>
#include <cstdint>
#include <climits>

using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int ret = 0;
            while(x!=0)
            {
                if((ret > (INT_MAX/10)) || (ret < (INT_MIN/10)))
                {
                    printf("ret=%d\n",ret);
                    return 0;
                }
                ret = ret*10 + x%10;
                x /= 10;
            }
            return ret;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->reverse(-2147483412) << endl;
    return 0;
}

