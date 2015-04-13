#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <stack>
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
        bool isLeafNode(TreeNode *node)
        {
            if((node->right == NULL) && (node->left==NULL))
            {
                return true;
            }
            return false;
        }
        bool hasPathSum(TreeNode *root, int sum) {
            if(root==NULL)
                return false;

#if 0
            if((root->left==NULL)&&(root->right==NULL))
            {
                if(root->val == sum)
                    return true;
                return false;        
            }

            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
#else
            int target = sum;
            TreeNode *node;
            stack<TreeNode *> sn;
            stack<int> st;
            sn.push(root);
            st.push(sum);
            while(!sn.empty())
            {
                node = sn.top();
                sn.pop();
                target = st.top();
                st.pop();
                if((node->left==NULL)&&(node->right==NULL))
                {
                    if(node->val == target)
                        return true;
                    continue;
                }

                target -= node->val;

                if(node->right)
                {
                    st.push(target);
                    sn.push(node->right);
                }
                if(node->left)
                {
                    st.push(target);
                    sn.push(node->left);
                }
            }

            return false;            
#endif
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    TreeNode *root = new TreeNode(1);
    cout << S->hasPathSum(root, 1) << endl;
    return 0;
}

