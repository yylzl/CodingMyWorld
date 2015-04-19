#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
#if 0
            int left = 0;
            int start = 0;
            int i = 0;
            while(1)
            {
                for(i=start;i<gas.size();++i)
                {
                    if(left+gas[i]-cost[i] < 0)
                    {
                        break;
                    }
                    left += gas[i] - cost[i];
                }
                if(i==gas.size())
                {
                    for(i=0;i<start;++i)
                    {
                        if(left+gas[i]-cost[i] < 0)
                        {
                            break;
                        }
                        left += gas[i] - cost[i];
                    }
                    if(i==start)
                    {
                        return start;
                    }
                    else
                    {
                        ++start;
                        left=0;
                    }
                }
                else
                {
                    start = i;
                    left = 0;
                }
                if(start >= gas.size())
                {
                    return -1;
                }
            }
#endif
#if 0
            int tank = 0;
            int total = 0;
            int start = 0;
            for(int i=0;i<gas.size();++i)
            {
                if((tank=tank+gas[i]-cost[i])<0)
                {
                    start = i+1;
                    total += tank;
                    tank = 0;
                }
            }
            return (total + tank < 0) ? -1 : start;
#endif
            int start = gas.size()-1;
            int end = 0;
            int sum = gas[start] - cost[start];
            while (start > end) {
                if (sum >= 0) {
                    sum += gas[end] - cost[end];
                    ++end;
                }
                else {
                    --start;
                    sum += gas[start] - cost[start];
                }
            }
            return sum >= 0 ? start : -1;       
        }       
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    //cout << S->canCompleteCircuit() << endl;
    return 0;
}

