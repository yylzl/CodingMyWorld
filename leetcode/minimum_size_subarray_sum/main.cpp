#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

class Solution {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            int sum = 0;
            int l = 0;
            int min_len = INT_MAX;
            for(int r=0;r<nums.size();++r)
            {
                sum+=nums[r];
                while(sum>=s)
                {
                    if(r-l+1<min_len)
                    {
                        min_len = r-l+1;
                    }
                    if(min_len==1)
                        return 1;
                    sum-=nums[l];
                    ++l;
                }
            }

            return min_len==INT_MAX?0:min_len;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    int a[] = {2,3,3,3,4,3,3};
    int l = sizeof(a)/sizeof(int);
    vector<int> nums(a,a+l);
    cout << S->minSubArrayLen(7, nums) << endl;
    return 0;
}

