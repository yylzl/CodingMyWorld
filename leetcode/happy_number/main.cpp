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
#if 0
        //链表是否有环的思路 一个快指针 一个慢指针 最终会相遇
        int digitSquareSum(int n) {
            int sum = 0, tmp;
            while (n) {
                tmp = n % 10;
                sum += tmp * tmp;
                n /= 10;
            }
            return sum;
        }

        bool isHappy(int n) {
            int slow, fast;
            slow = fast = n;
            do {
                slow = digitSquareSum(slow);
                fast = digitSquareSum(fast);
                fast = digitSquareSum(fast);
            } while(slow != fast);
            if (slow == 1) return 1;
            else return 0;
        }
#endif
        bool isHappy(int n) {
#if 0
            if(n<0)
            {
                return false;
            }
            vector<int> v;
            int sum = 0;
            while(1)
            {
                sum += (n%10)*(n%10);
                n/=10;
                if(n==0)
                {
                    if(sum==1)
                    {
                        return true;
                    }
                    if(find(v.begin(),v.end(),sum)!=v.end())
                    {
                        return false;
                    }
                    else
                    {
                        v.push_back(sum);
                        n = sum;
                        sum = 0;
                    }
                }
            }
#endif
            while(n>6){
                int next = 0;
                while(n){next+=(n%10)*(n%10); n/=10;}
                n = next;
            }
            return n==1;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->isHappy(19) << endl;
    cout << S->isHappy(0) << endl;
    cout << S->isHappy(-1) << endl;
    return 0;
}

