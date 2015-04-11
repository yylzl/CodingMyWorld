#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int nRows) {

            if(nRows <= 1)
            {
                return s;
            }

            string res = "";
            vector<string> tmp(nRows);
            int index = 0;
            int inx_max = nRows -1;
            for(int i=0;i<s.size();++i)
            {
                index = i%(2*inx_max);
                if(index > inx_max)
                {
                    index = 2*inx_max - index;
                }
                tmp[index] += s[i]; 
            }
            for(int i=0;i<tmp.size();++i)
            {
                res += tmp[i];
            }
            return res;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    string str = "PAYPALISHIRING";
    cout << S->convert(str, 3) << endl;
    return 0;
}

