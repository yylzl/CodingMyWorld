#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class Solution {
    public:
        string multiply(string num1, string num2) {
            int len1 = num1.length();
            int len2 = num2.length();
            string sum(len1+len2, '0');
            int carry = 0;
            for(int i=len1-1;i>=0;--i)
            {
                carry = 0;
                for(int j=len2-1;j>=0;--j)
                {
                    int tmp = sum[i+j+1]-'0' + (num1[i]-'0')*(num2[j]-'0') + carry;
                    sum[i+j+1] = tmp%10 + '0';
                    carry = tmp/10;
                }
                sum[i] += carry;
            }

            size_t start_pos = sum.find_first_not_of('0');
            if(start_pos!=string::npos)
            {
                return sum.substr(start_pos);
            }
            return "0";
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    string a = "11111";
    string b = "111";
    cout << S->multiply(a, b) << endl;
    return 0;
}

