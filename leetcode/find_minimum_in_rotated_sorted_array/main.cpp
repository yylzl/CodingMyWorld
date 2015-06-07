#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
    public:
        void findMin(vector<int>&nums, int start, int end, int &m)
        {
            if(start==end)
            {
                m = min(nums[start], nums[0]);
                return;
            }
            if((start + 1) == end)
            {
                m = min(nums[start], nums[end]);
                m = min(m, nums[0]);
                return;
            }
            int mid = (start + end)/2;
            //cout<<mid<<endl;
            if((nums[mid] < nums[mid+1])&&(nums[mid]<nums[mid-1]))
            {
                if(nums[mid]<nums[0])
                {
                    m = nums[mid];
                }
                else
                {
                    m = nums[0];
                }
            }
            else
            {
                if(nums[mid] > nums[0])
                {
                    findMin(nums, mid+1, end, m);
                }
                else
                {
                    findMin(nums, start, mid-1, m);
                }
            }
        }
        int findMin(vector<int>& nums) {
#if 0
            int size = nums.size();
            int ret = 0;
            //nums.push_back(INT_MAX);
            findMin(nums, 0, size-1, ret);
            return ret;
#else
            int start=0,end=nums.size()-1;

            while (start<end) {
                if (nums[start]<nums[end])
                    return nums[start];

                int mid = (start+end)/2;

                if (nums[mid]>=nums[start]) {
                    start = mid+1;
                } else {
                    end = mid-1;
                }
            }

            return nums[start];
#endif
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    int a1[] = {1};
    int a2[] = {3,2};
    int a3[] = {1,2,3};
    int a4[] = {2,3,0,1};
    int a5[] = {2,3,4,0,1};
    int a6[] = {5,1,2,3,4};

    vector<int> v1(a1,a1+1);
    vector<int> v2(a2,a2+2);
    vector<int> v3(a3,a3+3);
    vector<int> v4(a4,a4+4);
    vector<int> v5(a5,a5+5);
    vector<int> v6(a6,a6+5);

    cout << S->findMin(v1) << endl;
    cout << S->findMin(v2) << endl;
    cout << S->findMin(v3) << endl;
    cout << S->findMin(v4) << endl;
    cout << S->findMin(v5) << endl;
    cout << S->findMin(v6) << endl;
    return 0;
}

