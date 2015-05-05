#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
    public:
        static bool compare(int a, int b)
        {
            //
            string sa = to_string((long long)a) + to_string((long long)b);
            string sb = to_string((long long)b) + to_string((long long)a);
            return sa > sb;
            //好笨的方法
#if 0
            string sa = to_string((long long)a);
            string sb = to_string((long long)b);
            int la = sa.length();
            int lb = sb.length();
            int l = min(la,lb);
            int i;
            for(i=0;i<l;++i)
            {
                if(sa[i]-sb[i]>0)
                {
                    return true;
                }
                else if(sa[i]-sb[i]<0)
                {
                    return false;
                }
            }

            if(la > l)
            {
                while(i < la)
                {
                    if(sa[i]-sa[i-l]>0)
                    {
                        return true;
                    }
                    else if(sa[i]-sa[i-l]<0)
                    {
                        return false;
                    }
                    ++i;
                }
                i=0;
                while(i<la-1)
                {
                    if(sa[la-1] > sa[i])
                    {
                        return true;
                    }
                    ++i;
                }
            }

            if(lb > l)
            {
                while(i < lb)
                {
                    if(sb[i]-sb[i-l]>0)
                    {
                        return false;
                    }
                    else if(sb[i]-sb[i-l]<0)
                    {
                        return true;
                    }
                    ++i;
                }
                i=0;
                while(i<lb-1)
                {
                    if(sb[lb-1] > sb[i])
                    {
                        return false;
                    }
                    ++i;
                }
            }

            return la<lb;
#endif
        }
        string largestNumber(vector<int>& nums) {

            sort(nums.begin(), nums.end(), Solution::compare);

            string res = "";
            for(int i=0;i<nums.size();++i)
            {
                cout<<nums[i]<<" ";
                res += to_string((long long)nums[i]);
            }
            cout<<endl;
            return res;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    int a[] = {9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519};

    int n = sizeof(a)/sizeof(int);
    vector<int> nums(a, a+n);
    /*
    nums.push_back(3);
    nums.push_back(30);
    nums.push_back(34);
    nums.push_back(5);
    nums.push_back(9);
    */
    //nums.push_back(308);
    //nums.push_back(3088);
    /*
    for(int i=0;i<1000;++i)
    {
        nums.push_back(0);
    }*/
    string res = S->largestNumber(nums);
    cout << res << endl;
    return 0;
}

