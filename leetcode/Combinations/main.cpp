#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        void combine_backtrace(vector<vector<int> > &res, vector<int> &one, int start, int n, int k)
        {
            if(k==0)
            {
                res.push_back(one);
                return;
            }

            for(int i=start;i<=n;++i)
            {
                one.push_back(i);
                combine_backtrace(res, one, i+1, n, k-1);
                one.pop_back();
            }
        }
        vector<vector<int> > combine(int n, int k) {
            vector<vector<int> > res;
            vector<int> one;

            combine_backtrace(res, one, 1, n, k);
            return res;
        }

        //avoid push pop op
        vector<vector<int> > combine2(int n, int k) {
            v.resize(k);
            dfs(1, n, k);
            return r;
        }
    private:
        vector<vector<int> > r;
        vector<int> v;
        void dfs(int i, int n, int k) {
            while (i <= n) {
                v[v.size() - k] = i++;
                if (k > 1)
                    dfs(i, n, k - 1);
                else
                    r.push_back(v);
            }
        }

};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    vector<vector<int> > v;
    v = S->combine(5, 2);
    for(int i=0;i<v.size();++i)
    {
        cout<<"[";
        for(int j=0;j<v[i].size();++j)
        {
            cout<<v[i][j]<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}

