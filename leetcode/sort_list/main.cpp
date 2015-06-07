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

void dumpList(ListNode *head);
class Solution {
    public:
       //   Assume the length of list is n, which is unknown at the beginning.
       //   level log(n)         [ A0, A2, A3, ... , An-2, An-1 ]
       //   ...
       //   level 2        [ A0, A1, A2,  A3 ], [A4, A5, A6, A7] ,... , [ ..., An-2, An-1 ]
       //   level 1        [ A0, A1], [A2,  A3 ], [A4, A5], [A6, A7] ,... , [An-2, An-1]
       //   level 0        [ A0 ], [ A1] , [ A2 ],  [ A3 ],... , [ An-2 ], [ An-1 ]
       //   At each level, each group only contains at maximum 2^level elements. 
       //   Merge-sort theses groups pair by pair. Then level ++. Stop until 2^level > n. Assume the original input is :
       //   level 0        5, 3, 6, 1, 4, 2, 7
       //   After level 0, we got the length of the list and the list become:
       //   level 1        3, 5,   1, 6,    2, 4,    7
       //   Now each group contains 2 elements. After level 1, the list become:
       //   level 2        1, 3, 5, 6,    2, 4, 7
       //   Now each group contains 2^2 = 4 elements. After level 2, the list become:
       //   level 3        1, 2, 3, 4, 5, 6, 7
       //   Now, 2^3 > 7, stop.
        void merge(ListNode *l1, ListNode *l2, ListNode **head, ListNode **tail)
        {
            ListNode *dummyHead = new ListNode(0);
            ListNode *last = dummyHead;
            while(l1!=NULL&&l2!=NULL)
            {
                if(l1->val < l2->val)
                {
                    last->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    last->next = l2;
                    l2 = l2->next;
                }
                last = last->next;
            }

            while(l1!=NULL)
            {
                last->next = l1;
                l1 = l1->next;
                last = last->next;
            }

            while(l2!=NULL)
            {
                last->next = l2;
                l2 = l2->next;
                last = last->next;
            }

            *head = dummyHead->next;
            *tail = last;
        }
        ListNode *addNode(ListNode *head, ListNode *source, int count)
        {
            while(count > 0 && source !=NULL)
            {
                head->next = source;
                source = source->next;
                head = head->next;
                --count;
            }

            head->next = NULL;
            return source;
        }
        ListNode* sortList(ListNode* head) {
            if(head==NULL || head->next==NULL)
            {
                return head;
            }
            
            ListNode *dummyHead = new ListNode(0);
            ListNode *last = dummyHead;
            ListNode *dummyL1 = new ListNode(0);
            ListNode *dummyL2 = new ListNode(0);

            ListNode *mergedHead;
            ListNode *mergedTail;

            dummyHead->next = head;

            ListNode *visiter = head;

            int length = 0;
            int level = 0;

            while(visiter!=NULL&&visiter->next!=NULL)
            {
                visiter = addNode(dummyL1, visiter, 1<<level);
                visiter = addNode(dummyL2, visiter, 1<<level);
                merge(dummyL1->next, dummyL2->next, &mergedHead, &mergedTail);
                last->next = mergedHead;
                last = mergedTail;
                length += 2;
            }

            if(visiter!=NULL)
            {
                last->next = visiter;
                ++length;
            }

            level = 1;

            while(length > (1<<level))
            {
                last = dummyHead;
                visiter = dummyHead->next;
                while(visiter!=NULL)
                {
                    visiter = addNode(dummyL1, visiter, 1<<level);
                    visiter = addNode(dummyL2, visiter, 1<<level);
                    merge(dummyL1->next, dummyL2->next, &mergedHead, &mergedTail);
                    last->next = mergedHead;
                    last = mergedTail;
                }
                ++level;
            }
            
            return dummyHead->next;
        }
};

void dumpList(ListNode *head)
{
    while(head)
    {
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<"null"<<endl;
}

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    ListNode *head = new ListNode(7);
    ListNode *p = head;
    p->next = new ListNode(6);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(1);

    dumpList(head);
    head = S->sortList(head);
    dumpList(head);

    return 0;
}

