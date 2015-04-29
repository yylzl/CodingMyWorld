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
        //dp
        //m[l][i] = min(m[l+1][i],m[l+1][i+1]) + triangle[l][i]
        //计算完l之后l+1不需要继续保存，所以可以将二维转换为一维
        //m[i] = min[m[i], m[i+1]] + triangle[l][i];
        int minimumTotal(vector<vector<int> > &triangle) {
            int l = triangle.size();
            for(int i=l-2;i>=0;i--)
            {
                for(int j=0;j<=i;++j)
                {
                    triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
                }
            }
            return triangle[0][0];            
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    vector<vector<int> > triangle;
    vector<int> tmp, tmp1, tmp2;
    triangle.push_back(tmp);
    triangle.push_back(tmp1);
    triangle.push_back(tmp2);
    triangle[0].push_back(-1);
    triangle[1].push_back(2);
    triangle[1].push_back(3);
    triangle[2].push_back(1);
    triangle[2].push_back(-1);
    triangle[2].push_back(-3);
    cout << S->minimumTotal(triangle) << endl;
    return 0;
}

