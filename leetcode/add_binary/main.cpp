#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            string r = "";
            int i = a.size() - 1;
            int j = b.size() - 1;
            int c = 0;
            while(i>=0 || j>=0 || c>0)
            {
                c += i>=0?a[i--] - '0':0;
                c += j>=0?b[j--] - '0':0;
                r = (char)(c%2 + '0') + r;
                c /=2 ;
            }

            return r;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    string a = "11111";
    string b = "1";
    cout << S->addBinary(a, b) << endl;
    return 0;
}

