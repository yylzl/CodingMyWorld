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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
#if 0
        TreeNode *sortedListToBST(vector<int> &l, int start, int end)
        {
            if(start<=end)
            {
                int mid = (start+end)/2;
                TreeNode *node = new TreeNode(l[mid]);
                node->left = sortedListToBST(l, start, mid-1);
                node->right = sortedListToBST(l, mid+1, end);
                return node;
            }
            return NULL;
        }
        TreeNode* sortedListToBST(ListNode* head) {

            vector<int> l;
            while(head)
            {
                l.push_back(head->val);
                head = head->next;
            }

            TreeNode *r = sortedListToBST(l, 0, l.size()-1);
            return r;    
        }
#endif
        TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
        {
            if(head==NULL)
            {
                return NULL;
            }
            ListNode *fast = head;
            ListNode *slow = head;
            while(fast!=tail && fast->next!=tail)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            TreeNode *n = new TreeNode(slow->val);
            if(head!=slow)
            {
                n->left = sortedListToBST(head, slow);
            }
            if(slow->next!=tail)
            {
                n->right = sortedListToBST(slow->next, tail);
            }
            return n;

        }
        TreeNode* sortedListToBST(ListNode* head) {

            TreeNode *r = sortedListToBST(head, NULL);
            return r;
        }
};

void dumpTree(TreeNode *root)
{
    if(root==NULL)
    {
        cout<<"null"<<endl;
        return;
    }
    queue<TreeNode *> q;
    TreeNode *sentinel = new TreeNode(0);
    q.push(root);
    q.push(sentinel);
    TreeNode *n;
    while(!q.empty())
    {
        n = q.front();
        q.pop();

        if(n==sentinel)
        {
            if(!q.empty())
            {
                q.push(sentinel);
            }
            cout<<endl;
            continue;
        }

        if(n)
        {
            cout<<n->val<<" ";
            /*if(n->left==NULL&&n->right==NULL)
            {
                continue;
            }*/
            q.push(n->left);
            q.push(n->right);
        }
        else
        {
            cout<<"# ";
        }
    }
}

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    dumpTree(root);
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
    p = p->next;
    p->next = new ListNode(9);
    p = p->next;
    p->next = new ListNode(10);

    TreeNode *ret = S->sortedListToBST(head);
    dumpTree(ret);

    return 0;
}

