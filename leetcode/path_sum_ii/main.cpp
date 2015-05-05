#include <iostream>
#include <cstdint>
#include <climits>
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
#if 0
        void pathSum(vector<vector<int> > &r, vector<int> v, TreeNode *n, int sum, int cur)
        {
            if(n)
            {
                cur+=n->val;
                v.push_back(n->val);
                if(n->left==NULL&&n->right==NULL)
                {
                    if(cur==sum)
                    {
                        r.push_back(v);
                    }
                }
                if(n->left)
                {
                    pathSum(r, v, n->left, sum, cur);
                }
                if(n->right)
                {
                    pathSum(r, v, n->right, sum, cur);
                }
                cur-=n->val;
                v.pop_back();
            }
        }
#endif
        void pathSum(vector<vector<int> > &r, vector<int> v, TreeNode *n, int sum)
        {
            if(n)
            {
                v.push_back(n->val);
                if(n->left==NULL&&n->right==NULL&&n->val==sum)
                {
                    r.push_back(v);
                }
                if(n->left)
                {
                    pathSum(r, v, n->left, sum-n->val);
                }
                if(n->right)
                {
                    pathSum(r, v, n->right, sum-n->val);
                }
                v.pop_back();
            }
        }
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            vector<vector<int>> r;
            vector<int> v;
            //pathSum(r, v, root, sum, 0);
            pathSum(r, v, root, sum);
            return r;
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int> > r = S->pathSum(root, 22);

    for(int i=0;i<r.size();++i)
    {
        for(int j=0;j<r[i].size();++j)
        {
            cout<<r[i][j]<<" "; 
        }
        cout<<endl;
    }

    return 0;
}

