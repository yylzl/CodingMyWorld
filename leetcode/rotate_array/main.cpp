#include <iostream>
#include <cstdint>
#include <cstring>
#include <climits>
#include <stack>

//还有一种求最大公约数的循环链的解法没搞明白
//stl rotate算法

using namespace std;

void swap(int nums[], int x, int y)
{
    int temp = nums[x];
    nums[x] = nums[y];
    nums[y] = temp;
}

class Solution {
    public:
    void rotate(int nums[], int n, int k) {
        if(k<=0)
                return;
        if(k>n)
                k=k%n;
#if 0
        int *t = (int *)malloc(k*sizeof(int));
        memcpy(t, nums+n-k, k*sizeof(int));
        memmove(nums+k, nums, (n-k)*sizeof(int));
        memcpy(nums, t, k*sizeof(int));
#else
        int i = 0;
        for(i=0;i<(n-k)/2;++i)
        {
            swap(nums, i, n-k-i-1);
        }
        for(i=n-k;i<n-k+k/2;++i)
        {
            swap(nums, i, n+n-k-i-1);
        }
        for(i=0;i<n/2;++i)
        {
            swap(nums, i, n-i-1);
        }
#endif
    }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    int nums[] = {1, 2, 3};
    S->rotate(nums, 3, 1);
    for(int i = 0; i < 3; ++i)
    {
        cout << nums[i] << endl;
    }
    return 0;
}

