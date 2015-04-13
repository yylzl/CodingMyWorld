#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int front = 0;
            int end = s.size() - 1;

            while(front < end)
            {
                if(isalnum(s[front]) && isalnum(s[end]))
                {
                    if(tolower(s[front])==tolower(s[end]))
                    {
                        ++front;
                        --end;
                    }
                    else
                    {
                        return false;
                    }
                }
                if(!isalnum(s[front]))
                {
                    ++front;
                }
                if(!isalnum(s[end]))
                {
                    --end;
                }
            }

            return true;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    string str1 = "PAYPALISHIRING";
    string str2 = "A man, a plan, a canal: Panama";
    cout << S->isPalindrome(str1) << endl;
    cout << S->isPalindrome(str2) << endl;
    return 0;
}

