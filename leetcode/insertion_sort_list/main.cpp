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
        ListNode* insertionSortList(ListNode* head) {
            if(head==NULL || head->next==NULL)
            {
                return head;
            }

            ListNode *dummyHead = new ListNode(0);
            ListNode *prefind;
            ListNode *find;

            //dummyHead->next = head;
            //head=head->next;
            //dummyHead->next->next=NULL;

            while(head)
            {
                prefind = dummyHead;
                find = dummyHead->next;
                while((find!=NULL)&&(head->val>find->val))
                {
                    find=find->next;
                    prefind = prefind->next;
                }
                prefind->next = head;
                head=head->next;
                prefind->next->next=find;
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
    head = S->insertionSortList(head);
    dumpList(head);

    return 0;
}

