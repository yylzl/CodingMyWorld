#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void rightSideView(TreeNode *root, vector<int> &v, int level)
        {
            if(root)
            {
                if(v.size() <= level)
                {
                    v.push_back(root->val);
                }
                rightSideView(root->right, v, level+1);
                rightSideView(root->left, v, level+1);
            }
        }

        vector<int> rightSideView(TreeNode *root) {
            vector<int> ret;
            if(root==NULL)
            {
                return ret;
            }
            queue<TreeNode *> q;
            q.push(root);
            q.push(NULL);
            TreeNode *node;
            bool right = true;
            while(!q.empty())
            {
                node = q.front();
                q.pop();
                if(node)
                {
                    if(right)
                    {
                        ret.push_back(node->val);
                        right = false;
                    }
                    if(node->right)
                    {
                        q.push(node->right);
                    }
                    if(node->left)
                    {
                        q.push(node->left);
                    }
                }
                else
                {
                    if(!q.empty())
                    {
                        q.push(NULL);
                        right = true;
                    }
                }
            }

            return ret;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    TreeNode *root = new TreeNode(1);
    //cout << S->levelOrder(root) << endl;
    return 0;
}

