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

class Solution {
    public:
#if 0
        void preorder(TreeNode* root, queue<TreeNode *> &q) {
            if(root)
            {
                q.push(root);
                preorder(root->left, q);
                preorder(root->right, q);
            }
        }
        void flatten(TreeNode* root) {
            if(root==NULL)
            {
                return;
            }
            queue<TreeNode *> q;
            preorder(root, q);
            TreeNode *pre = q.front();
            q.pop();
            TreeNode *node = NULL;
            while(!q.empty())
            {
                node = q.front();
                q.pop();
                pre->right = node;
                pre->left = NULL;
                pre = node;
            }
        }    
#endif
    //Morris traversal O(n) time O(1) space tree traversal
    //找到prev前驱节点利用右子树的空指针形成环，第二次遍历到的时候恢复树的结构将右指针置为空
    void flatten(TreeNode* root)
    {
        while(root)
        {
            if(root->left==NULL)
            {
                root=root->right;
            }
            else
            {
                TreeNode *prev = root->left;
                while(prev->right)
                {
                    prev = prev->right;
                }
                prev->right = root->right;

                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);

    S->flatten(root);

    while(root)
    {
        cout<<root->val<<endl;
        cout<<root->left<<endl;
        root=root->right;
    }
    return 0;
}

