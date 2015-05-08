#include <iostream>
#include <cstdint>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* buildTree(vector<int>::iterator in_s, vector<int>::iterator in_e, vector<int>::iterator post_s, vector<int>::iterator post_e) {
            if(in_s>=in_e || post_s>=post_e)
            {
                return NULL;
            }

            vector<int>::iterator it = find(in_s, in_e, *(post_e-1));
            TreeNode *node = new TreeNode(*it);
            node->left = buildTree(in_s, it, post_s, post_s+(it-in_s));
            node->right = buildTree(it+1, in_e, post_s+(it-in_s), post_e-1);
            return node;

        }        
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
#if 0
            return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
#endif
            //straightforward solution need study //https://leetcode.com/discuss/15115/my-comprehension-of-o-n-solution-from-%40hongzhi
            if(inorder.size() == 0)return NULL;
            TreeNode *p;
            TreeNode *root;
            stack<TreeNode *> stn;

            root = new TreeNode(postorder.back()); 
            stn.push(root); 
            postorder.pop_back(); 

            while(true)
            {
                if(inorder.back() == stn.top()->val) 
                {
                    p = stn.top();
                    stn.pop(); 
                    inorder.pop_back(); 
                    if(inorder.size() == 0) break;
                    if(stn.size() && inorder.back() == stn.top()->val)
                        continue;
                    p->left = new TreeNode(postorder.back()); 
                    postorder.pop_back();
                    stn.push(p->left);
                }
                else 
                {
                    p = new TreeNode(postorder.back());
                    postorder.pop_back();
                    stn.top()->right = p; 
                    stn.push(p); 
                }
            }
            return root;
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
    int a[] = {4,2,1,5,3,6};
    int b[] = {4,2,5,6,3,1};
    vector<int> inorder(a,a+6);
    vector<int> postorder(b,b+6);
    TreeNode *root = S->buildTree(inorder, postorder);
    dumpTree(root);

    return 0;
}

