#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        int rob(vector<int> &num) {
#if 1
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
                    int size = num.size();
                    vector<int> rob_sum(size);
                    rob_sum[0] = 0;
                    rob_sum[1] = num[0];
                    rob_sum[2] = max(num[0], num[1]);
                    for(int i=3;i<size;++i)
                    {
                        rob_sum[i] = max(rob_sum[i-1], rob_sum[i-2] + num[i-1]);
                    }

                    int max_rob = rob_sum[size-1];
                    cout<<max_rob<<endl;


                    rob_sum[0] = 0;
                    rob_sum[1] = num[1];
                    rob_sum[2] = max(num[1], num[2]);
                    for(int i=4;i<=size;++i)
                    {
                        rob_sum[i-1] = max(rob_sum[i-2], rob_sum[i-3] + num[i-1]);
                    }

                    cout<<rob_sum[size-1]<<endl;

                    return max(rob_sum[size-1], max_rob);

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

