#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<string> > groupAnagrams(vector<string>& strs) {
            unordered_map<string, multiset<string> > m;
            for(int i=0;i<strs.size();++i)
            {
                string t = strs[i];
                sort(t.begin(),t.end());
                m[t].insert(strs[i]);
            }

            vector<vector<string> > anagrams;
            for (auto i=m.begin();i!=m.end();++i) { 
                vector<string> anagram(i->second.begin(), i->second.end());
                anagrams.push_back(anagram);
            }
            return anagrams;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    vector<string> strs;
    strs.push_back("abc");
    strs.push_back("abc");
    strs.push_back("bca");
    strs.push_back("deft");
    strs.push_back("edtf");
    strs.push_back("tfed");
    strs.push_back("ftde");

    vector<vector<string> > ret;
    ret = S->groupAnagrams(strs);

    for(int i=0;i<ret.size();++i)
    {
        for(int j=0;j<ret[i].size();++j)
        {
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

