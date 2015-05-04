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
#if 0
        void generateParenthesis(vector<string> &v, string s, int left, int right) 
        {
            if(left==0&&right==0)
            {
                v.push_back(s);
            }

            if(left > 0)
            {
                generateParenthesis(v, s+"(", left-1, right+1);
            }
            if(right > 0)
            {
                generateParenthesis(v, s+")", left, right-1);
            }
        }
        vector<string> generateParenthesis(int n) {
            vector<string> ret;
            generateParenthesis(ret, "", n, 0);
            return ret;
        }        
#endif
#if 0
        //dp solution
        //f(0): ""
        //f(1): "("f(0)")"
        //f(2): "("f(0)")"f(1), "("f(1)")"
        //f(3): "("f(0)")"f(2), "("f(1)")"f(1), "("f(2)")"
        //So f(n) = "("f(0)")"f(n-1) , "("f(1)")"f(n-2) "("f(2)")"f(n-3) ... "("f(i)")"f(n-1-i) ... "(f(n-1)")"
        vector<string> generateParenthesis(int n) {
            vector<vector<string> > res;
            vector<string> tmp;
            tmp.push_back("");
            res.push_back(tmp);
            for(int i=1;i<=n;++i)
            {
                vector<string> t;
                res.push_back(t);
                for(int j=0;j<i;++j)
                {
                    for(int k=0;k<res[j].size();++k)
                    {
                        for(int l=0;l<res[i-1-j].size();++l)
                        {
                            res[i].push_back("("+res[j][k]+")"+res[i-1-j][l]);
                        }
                    }
                }
            }
            return res[n];
        }        
#endif
        //using stack
        vector<string> generateParenthesis(int n) {
            vector<string> ret;
            stack<string> strstack;
            stack<int> right;
            strstack.push("(");
            right.push(0);
            string s = "";
            int r = 0;
            while(!strstack.empty())
            {
                s = strstack.top();
                strstack.pop();
                r = right.top();
                right.pop();

                if(s.length()==(2*n))
                {
                    ret.push_back(s);
                    continue;
                }
                
                if((s.length()-r) < n)
                {
                    strstack.push(s+"(");
                    right.push(r);
                }

                if((2*r) < s.length())
                {
                    strstack.push(s+")");
                    right.push(r+1);
                }
            }
            return ret;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    vector<string> ret = S->generateParenthesis(3);
    for(int i=0;i<ret.size();++i)
    {
        cout<<ret[i]<<" ";
    }
    cout<<endl;
    return 0;
}

