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
        //gcd(a,b) = gcd(b,a mod b)
        int gcd(int a, int b)
        {
            int tmp;
            if(a < b)
            {
                tmp = a;
                a = b;
                b = tmp;
            }
            while(b!=0)
            {
                tmp = b;
                b = a%b;
                a = tmp;
            }

            return a;
        }
#if 1
        string fractionToDecimal(int numerator, int denominator) {
            ostringstream os;
            //dealing with denominator == 0
            if (denominator == 0){
                os << INT_MAX;
                return os.str();
            }
            //dealing with numerator == 0
            if(numerator==0)
                return "0";
            //others
            if ((numerator<0) ^ (denominator < 0))
                os << '-';
            long long x = abs((long long)numerator), y = abs((long long)denominator);
            os << x / y;
            if ((x %= y) == 0)
                return os.str();
            os << '.';

            long long ax = x, ay = y;
            int i = 0, j = 0;
            //find the count of non_repeating part,it depends on how many 2 or 5 factor 
            // are there in denominator
            while (y % 2 == 0){
                y /= 2;
                ++i;
            }
            while (y % 5 == 0){
                y /= 5;
                ++j;
            }
            int k = max(i, j);
            //non_repeating part
            while (k != 0 && ax != 0){
                ax = ax * 10;
                os << ax / ay;
                ax %= ay;
                --k;
            }
            if (ax == 0)
                return os.str();
            long long m = ax;
            os << '(';
            //repeating part
            //to find the repeating part ,we need to find when the denominator(here it is ax) repeats,
            //then we stop;
            while (true){
                ax = ax * 10;
                os << ax / ay;
                if ((ax %= ay) == m)
                    break;
            }
            os << ')';
            return os.str();
        }
#else
        string fractionToDecimal(int numerator, int denominator) {
            if(numerator==0)
            {
                return "0";
            }
            string res = "";
            if((numerator < 0)^(denominator < 0))
            {
                res += "-";
            }

            int64_t n = numerator;
            int64_t d = denominator;
            n = abs(n);
            d = abs(d);

            long long q = n/d;
            int64_t r = n%d;
            res += to_string(q);
            if(r==0)
            {
                return res;
            }
            else
            {
                res += ".";
            }
            unordered_map<int, int> m;
            //出现相同的余数代表开始循环
            while(r)
            {
                if(m.find(r)!=m.end())
                {
                    res.insert(m[r], 1, '(');
                    res+=")";
                    break;
                }
                m[r] = res.length();
                r=r*10;
                q=r/d;
                res += to_string(q);
                r=r%d;
            }

            return res;
        }   
#endif     
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    //cout << S->gcd(4, 7) << S->gcd(8, 6) << endl;
    cout << S->fractionToDecimal(4,313) << endl;
    return 0;
}

