#include <iostream>
#include <cstdint>
#include <climits>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    TreeNode *node;
    ListNode *next;
    ListNode(TreeNode *p) : node(p), next(NULL) {}
};

void dumpList(ListNode *head);

class BSTIterator {
    private:
        ListNode *head;
        ListNode *cur;
        void inordertravel(TreeNode *root)
        {
            if(root)
            {
                if(root->left)
                    inordertravel(root->left);

                //cout << root->val << endl;
                ListNode *node = new ListNode(root);
                cur->next = node;
                cur = cur->next;

                if(root->right)
                    inordertravel(root->right);

            }
        }
    public:
        BSTIterator(TreeNode *root) {
            head = new ListNode(NULL);
            cur = head;
            inordertravel(root);
            cur = head;
            //dumpList(head->next);
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return cur->next!=NULL;
        }

        /** @return the next smallest number */
        int next() {
            int ret = cur->next->node->val;
            cur = cur->next;
            return ret;
            
        }
};

/**
 ** Your BSTIterator will be called like this:
 ** BSTIterator i = BSTIterator(root);
 ** while (i.hasNext()) cout << i.next();
 **/

void dumpList(ListNode *head)
{
    while(head)
    {
        cout<<head->node->val<<"->";
        head=head->next;
    }
    cout<<"null"<<endl;
}

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
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(4);
    root->right = new TreeNode(9);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(8);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(1);

    BSTIterator *bit = new BSTIterator(root);

    while(bit->hasNext())
    {
        cout<<bit->next()<<endl;
    }

    return 0;
}

