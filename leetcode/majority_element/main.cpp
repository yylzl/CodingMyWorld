#include <iostream>
#include <cstdint>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/* 
   1.Runtime: O(n2) — Brute force solution: Check each element if it is the majority element.
   2.Runtime: O(n), Space: O(n) — Hash table: Maintain a hash table of the counts of each element, then find the most common one.
   3.Runtime: O(n log n) — Sorting: As we know more than half of the array are elements of the same value, we can sort the array and all majority elements will be grouped into one contiguous chunk. Therefore, the middle (n/2th) element must also be the majority element.
   4.Average runtime: O(n), Worst case runtime: Infinity — Randomization: Randomly pick an element and check if it is the majority element. If it is not, do the random pick again until you find the majority element. As the probability to pick the majority element is greater than 1/2, the expected number of attempts is < 2.
   5.Runtime: O(n log n) — Divide and conquer: Divide the array into two halves, then find the majority element A in the first half and the majority element B in the second half. The global majority element must either be A or B. If A == B, then it automatically becomes the global majority element. If not, then both A and B are the candidates for the majority element, and it is suffice to check the count of occurrences for at most two candidates. The runtime complexity, T(n) = T(n/2) + 2n = O(n log n).
   6.Runtime: O(n) — Moore voting algorithm: We maintain a current candidate and a counter initialized to 0. As we iterate the array, we look at the current element x:
   If the counter is 0, we set the current candidate to x and the counter to 1.
   If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
   After one pass, the current candidate is the majority element. Runtime complexity = O(n).
   7.Runtime: O(n) — Bit manipulation: We would need 32 iterations, each calculating the number of 1's for the ith bit of all n numbers. Since a majority must exist, therefore, either count of 1's > count of 0's or vice versa (but can never be equal). The majority number’s ith bit must be the one bit that has the greater count.

   Update (2014/12/24): Improve algorithm on the O(n log n) sorting solution: We do not need to 'Find the longest contiguous identical element' after sorting, the n/2th element is always the majority.

   Analysis written by @ts and @1337c0d3r.


   5和7没有实现，7复杂，5觉得有问题。
   */

class Solution {
    public:
        int majorityElement(vector<int> &num) {
#if 0 
            //6.moore voting algorithm           
            int count = 0;
            int ret = 0;
            for(int i=0;i<num.size();++i)
            {
                if(count==0)
                {
                    ret = num[i];
                    count = 1;
                }
                else
                {
                    if(ret==num[i])
                    {
                        ++count;
                    }
                    else
                    {
                        --count;
                    }
                }
            }

            return ret;
#endif
#if 0
            //2.hash table
            map<int, int> m;
            map<int, int>::iterator it;
            for(int i=0;i<num.size();++i)
            {
                it = m.find(num[i]);
                if(it!=m.end())
                {
                    it->second +=1;
                }
                else
                {
                    m.insert(pair<int,int>(num[i], 1));
                }
            }
            int ret =0;
            int count = 0;
            for(it=m.begin();it!=m.end();++it)
            {
                if(it->second > count)
                {
                    count = it->second;
                    ret = it->first;
                }
            }

            return ret;        
#endif
#if 0
        //3.sort
        sort(num.begin(), num.end());
        return num[num.size()/2];        
#endif
#if 1
        //4.random
        int ret;
        int count;
        if(num.size()==1)
            return num[0];
        while(1)
        {
            count = 0;
            ret = num[random()%(num.size()-1)];
            for(int i=0; i<num.size(); ++i)
            {
                if(ret==num[i])
                {
                    ++count;
                }
            }
            if(count > num.size()/2)
            {
                return ret;
            }
        }        
#endif
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    cout << S->majorityElement(num) << endl;
    return 0;
}

