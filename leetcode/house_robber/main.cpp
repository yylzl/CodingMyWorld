#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        int rob(vector<int> &num) {
#if 0
            cout << num.size() << endl;
            switch(num.size())
            {
                case 0:
                    return 0;
                case 1:
                    return num[0];
                case 2:
                    return max(num[0], num[1]);
                default:
                    vector<int> rob_sum(num.size()+1);
                    rob_sum[0] = 0;
                    rob_sum[1] = num[0];
                    rob_sum[2] = max(num[0], num[1]);
                    for(int i=3;i<=num.size();++i)
                    {
                        rob_sum[i] = max(rob_sum[i-1], rob_sum[i-2] + num[i-1]);
                    }
                    return rob_sum[num.size()];
            }
#else
            int last[2] = {0};
            bool mark = false;
            for (int i = 0; i < num.size(); i++) {
                last[!mark] = max(last[mark], last[!mark] + num[i]);
                mark = !mark;
            }
            return last[mark];
#endif
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    vector<int> num(6);
    num[0] = (2);
    num[1] = (4);
    num[2] = (8);
    num[3] = (9);
    num[4] = (9);
    num[5] = (3);
    cout << S->rob(num) << endl;
    return 0;
}

