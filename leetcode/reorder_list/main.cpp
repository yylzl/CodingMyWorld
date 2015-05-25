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
        void reorderList(ListNode* head) {
            if(head==NULL)
                return;
            if(head->next==NULL)
                return;
            if(head->next->next==NULL)
                return;

            ListNode *p1 = head;
            ListNode *p2 = head;
            ListNode *p3 = head;
            stack<ListNode *> s;
            while(p3->next!=NULL&&p3->next->next!=NULL)
            {
                p2=p2->next;
                p3=p3->next->next;
            }

            p2=p2->next;
            while(p2)
            {
                s.push(p2);
                p2=p2->next;
            }

            while(!s.empty())
            {
                p3 = s.top();
                s.pop();
                if(p1==p3)
                {
                    p1->next=NULL;
                    return;
                }
                p3->next = p1->next;
                p1->next = p3;
                p1 = p3->next;
            }
            p1->next = NULL;
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

    dumpList(head);
    S->reorderList(head);
    dumpList(head);

    return 0;
}

