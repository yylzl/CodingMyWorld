#include <iostream>
#include <cstdint>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            if(n==0)
                return 1.0;

            if(n<0)
            {
                x = 1/x;
                if(n==INT_MIN)
                {
                    n=INT_MIN/2;
                    x*=x;
                }
                n = -n;
            }

            double ret = 1.0;
            while(n)
            {
                if(n&1)
                    ret *= x;
                x *= x;
                cout<<x<<" "<<ret<<endl;
                n=n>>1;
            }

            return ret;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->myPow(8.88023, 3)<< endl;
    return 0;
}

