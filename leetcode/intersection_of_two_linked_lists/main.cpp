#include <iostream>
#include <cstdint>
#include <climits>
#include <string>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
#if 0
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if((headA==NULL) || (headB==NULL))
            {
                return NULL;
            }

            int l1 = 1;
            ListNode *pA = headA;
            while(pA->next!=NULL)
            {
                pA=pA->next;
                l1++;
            }
            int l2 = 1;
            ListNode *pB = headB;
            while(pB->next!=NULL)
            {
                pB=pB->next;
                l2++;
            }

            if(pA!=pB)
            {
                return NULL;
            }
            pA=headA;
            pB=headB;
            int diff = l2-l1;
            if(diff>0)
            {
                while(diff)
                {
                    pB = pB->next;
                    --diff;
                }
            }
            else
            {
                while(diff)
                {
                    pA = pA->next;
                    ++diff;
                }
            }

            while(pA!=pB)
            {
                pA = pA->next;
                pB = pB->next;
            }
            return pA;
        }        
#else
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if((headA==NULL) || (headB==NULL))
            {
                return NULL;
            }

            ListNode *pA = headA;
            ListNode *pB = headB;
            ListNode *pALast = NULL;
            ListNode *pBLast = NULL;
            while(1)
            {
                if(pA==pB)
                {
                    return pA;
                }
                if(pA->next==NULL)
                {
                    pALast = pA;
                    pA = headB;
                    if(pBLast!=NULL)
                    {
                        if(pALast!=pBLast)
                        {
                            return NULL;
                        }
                    }

                }
                else
                {
                    pA=pA->next;
                }
                if(pB->next==NULL)
                {
                    pBLast = pB;
                    pB = headA;
                    if(pALast!=NULL)
                    {
                        if(pALast!=pBLast)
                        {
                            return NULL;
                        }
                    }
                }
                else
                {
                    pB=pB->next;
                }
            }
        }        
#endif
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    return 0;
}

