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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val) {
            ListNode *dummyHead = new ListNode(0);
            dummyHead->next = head;
            ListNode *cur = dummyHead->next;
            ListNode *pre = dummyHead;
            while(cur)
            {
                if(cur->val==val)
                {
                    pre->next = cur->next;
                    //need free cur?
                }
                else
                {
                    pre = cur;
                }
                cur = cur->next;
            }
            return dummyHead->next;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    return 0;
}

