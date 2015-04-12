#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <stack>

using namespace std;

class Solution {
    public:
        int atoi(string str) {
            if(str.empty())
            {
                cout << "input error:" << str << endl;
                return 0;
            }
            int sign = 1;
            int start = 0;
            int64_t ret = 0;
            for(int i=0;i<str.size();++i)
            {
                switch(str[i])
                {
                    case ' ':
                        if(start==1)
                        {
                            return ret*sign;
                        }
                        break;
                    case '+':
                        if(start==0)
                        {
                            start = 1;
                        }
                        else
                        {
                            return 0;
                        }
                        break;
                    case '-':
                        if(start==0)
                        {
                            sign = -1;
                            start = 1;
                        }
                        else
                        {
                            return 0;
                        }
                        break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        start = 1;
                        ret = ret*10 + str[i] - '0';
                        if(ret*sign >= INT_MAX)
                        {
                            return INT_MAX;
                        }
                        if(ret*sign <= INT_MIN)
                        {
                            return INT_MIN;
                        }
                        break;
                    default:
                        if(start == 1)
                        {
                            if(sign!=0)
                            {
                                return ret*sign;
                            }
                            return ret;
                        }
                        else
                        {
                            return 0;
                        }
                        break;
                }
            }

            return ret*sign;
        }
};

int main(int argc, char *argv[])
{
    Solution *s = new Solution();
    cout << s->atoi("+1234") << endl;
    cout << s->atoi("-1234") << endl;
    cout << s->atoi("-+1234") << endl;
    cout << s->atoi("+-1234") << endl;
    cout << s->atoi("ab1234") << endl;
    cout << s->atoi("12a34") << endl;
    cout << s->atoi("12 34 5") << endl;
    cout << s->atoi("2147483647") << endl;
    cout << s->atoi("2147483648") << endl;
    cout << s->atoi("-2147483648") << endl;
    cout << s->atoi("-2147483647") << endl;
    cout << s->atoi("-2147483649") << endl;
    return 0;
}

