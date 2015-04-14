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
        void levelOrder(TreeNode *root, vector<vector<int> > v, int level)
        {
            if(root==NULL)
                return;
            if(level >= v.size())
            {
                v.push_back(vector<int>());
            }

            v[level].push_back(root->val);
            levelOrder(root->left, v, level+1);
            levelOrder(root->right, v, level+1);
        }
        vector<vector<int> > levelOrder(TreeNode *root) {

#if 0
            //two stack
            vector<vector<int> > ret;
            if(root==NULL)
                return ret;
            
            vector<int> l;

            stack<TreeNode *> s1;
            stack<TreeNode *> s2;
            TreeNode *node;
            s1.push(root);

            while((!s1.empty()) || (!s2.empty()))
            {
                while(!s1.empty())
                {
                    node = s1.top();
                    s2.push(node);
                    s1.pop();
                    l.push_back(node->val);
                    if(s1.empty())
                    {
                        ret.push_back(l);
                        l.clear();
                    }
                }
                
                while(!s2.empty())
                {
                    node = s2.top();
                    s2.pop();

                    if(node->right)
                        s1.push(node->right);
                    if(node->left)
                        s1.push(node->left);
                }
            }

            return ret;
#endif
#if 0
            //one queue
            vector<vector<int> > ret;
            if(root==NULL)
                return ret;
            
            vector<int> l;

            queue<TreeNode *> q;
            TreeNode *node;
            q.push(root);
            q.push(NULL);

            while(!q.empty())
            {
                node = q.front();
                q.pop();

                if(node==NULL)
                {
                    ret.push_back(l);
                    l.clear();
                    if(q.size()>0)
                    {
                        q.push(NULL);
                    }
                }
                else
                {
                    l.push_back(node->val);
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                }

            }

            return ret;
#endif
#if 1
            //recursive
            vector<vector<int> > ret;
            levelOrder(root, ret, 0);
            return ret;
#endif
        }     
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    TreeNode *root = new TreeNode(1);
    //cout << S->levelOrder(root) << endl;
    return 0;
}

