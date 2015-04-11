#include <iostream>
#include <cstdint>
#include <climits>
#include <string>

using namespace std;

class Solution {
    public:
        int compareVersion(string version1, string version2) {
            string::size_type f1 = version1.find('.');
            string::size_type f2 = version2.find('.');
            int v1 = stoi(version1.substr(0, f1));
            int v2 = stoi(version2.substr(0, f2));
            if(v1==v2)
            {
                if((f1==string::npos) && (f2==string::npos))
                {
                    return 0;
                }
                else if((f1==string::npos) && (f2!=string::npos))
                {
                    return compareVersion("0", version2.substr(f2+1, string::npos));
                }
                else if((f1!=string::npos) && (f2==string::npos))
                {
                    return compareVersion(version1.substr(f1+1, string::npos), "0");
                }
                else
                {
                    return compareVersion(version1.substr(f1+1, string::npos), version2.substr(f2+1, string::npos));
                }
            }
            else if(v1>v2)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    cout << S->compareVersion("1", "1.1") <<endl;
    cout << S->compareVersion("10.6.5", "10.6") <<endl;
    return 0;
}

