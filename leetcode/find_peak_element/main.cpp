#include <iostream>
#include <cstdint>
#include <climits>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int n = nums.size();
            if(n<2)
            {
                return 0;
            }

            if(nums[0] > nums[1])
            {
                return 0;
            }
            if(nums[n-1] > nums[n-2])
            {
                return n-1;
            }

#if 0
            for(int i=1;i<n-1;++i)
            {
                //there must be a peak
                if(nums[i] > nums[i+1])
                {
                    return i;
                }
            }
#endif
            int low = 1;
            int hight = n-2;

            while(low < hight)
            {
                if(nums[low] > nums[low+1])
                {
                    return low;
                }

                if(nums[hight] > nums[hight-1])
                {
                    return hight;
                }
                low++;
                hight--;
            }

            return low;

#if 0
            //binary search
            //if nums[mid] > nums[mid+1] and mid not a peak
            //there must be a peak in nums[0...mid-1]
            //nums[mid-...] > nums[mid-1] > nums[mid] -> nums[0] > nums[1] -> nums[0] is peak because nums[-1] is 负无穷
            int low = 0;
            int hight = n-1;
            
            int mid;
            while(low < hight)
            {
                mid = (low+hight)/2;
                if((nums[mid] > nums[mid+1])&&nums[mid]>nums[mid-1])
                {
                    return mid;
                }
                else if(nums[mid]>nums[mid+1])
                {
                    hight = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            return low;
#endif
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    return 0;
}

