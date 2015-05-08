#include <iostream>
#include <cstdint>
#include <climits>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *reverseList(ListNode **head, ListNode *cur)
        {
            if(cur->next==NULL)
            {
                *head = cur;
                return cur;
            }
            ListNode *pre = reverseList(head, cur->next);
            pre->next = cur;
            cur->next = NULL;
            return cur;
        }
        ListNode* reverseList(ListNode* head) {
            if(head==NULL)
            {
                return NULL;
            }
            if(head->next==NULL)
            {
                return head;
            }
            ListNode *ret;
            reverseList(&ret, head);
            return ret;
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

    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(6);
    p = p->next;
    p->next = new ListNode(7);
    p = p->next;
    p->next = new ListNode(8);

    dumpList(head);
    head = S->reverseList(head);
    dumpList(head);

    return 0;
}

