#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    public:
        void letterCombinations(string digits, int s, int e, vector<string> &v, string str, string phone_letter[])
        {
            if(s==e)
            {
                v.push_back(str);
                return;
            }
            for(int j = 0; j < phone_letter[digits[s]-'2'].size();++j)
            {
                str = str + phone_letter[digits[s]-'2'][j];
                letterCombinations(digits, s+1, e, v, str, phone_letter);
                str = str.substr(0, str.size()-1);
            }
        }
        vector<string> letterCombinations(string digits) {
            vector<string> ret;
            if(digits.empty())
                return ret;
            string str = "";
            string phone_letter[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            letterCombinations(digits, 0, digits.size(), ret, str, phone_letter);
            return ret;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    vector<string> vs = S->letterCombinations("235");
    for(int i = 0; i < vs.size(); ++i)
    {
        cout << vs[i] <<" ";
    }
    cout << endl;
    return 0;
}

