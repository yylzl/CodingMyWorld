#include <iostream>
#include <cstdint>
#include <climits>
#include <stack>

using namespace std;

class Solution {
    public:
    bool isValid(string s) {
        if(s.length()%2==1)
        {
            return false;
        }

        stack<char> t;
        t.push(s[0]);
        for(int i=1;i<s.length();++i)
        {
            if(((s[i]==')') && (t.top()=='(')) || ((s[i]=='}') && (t.top()=='{')) || ((s[i]==']') && (t.top()=='[')))
            {
                t.pop();
            }
            else
            {
                t.push(s[i]);
            }
        }
        return t.empty();
    }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    if(S->isValid("([[[[[]]]]]{)"))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}

