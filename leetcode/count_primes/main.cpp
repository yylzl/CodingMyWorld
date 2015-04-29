#include <iostream>
#include <cstdint>
#include <climits>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int countPrimes(int n) {
            bool A[n];
            int i,j;
            for(i=2;i<n;++i)
            {
                A[i] = true;
            }
            for(i = 2; i < sqrt(n);++i)
            {
                if(A[i])
                {
                    for(j=i*i;j<n;j=j+i)
                    {
                        A[j] = false;
                    }
                }
            }

            int cnt = 0;

            for(i=2;i<n;++i)
            {
                if(A[i])
                {
                    ++cnt;
                    cout << i << endl;        
                }
            }
            return cnt;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    S->countPrimes(30);
    return 0;
}

