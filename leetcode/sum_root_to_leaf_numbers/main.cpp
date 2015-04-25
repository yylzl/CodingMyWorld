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
        void sumNumbers(TreeNode *root, int &sum, int num)
        {
            if(root)
            {
                num = num *10 + root->val;
                if(root->left)
                {
                    sumNumbers(root->left, sum, num);
                }
                if(root->right)
                {
                    sumNumbers(root->right, sum, num);
                }
                if(root->left==NULL && root->right==NULL)
                {
                    sum += num;
                }
            }
        }
        //超过INT_MAX和小于INT_MIN的问题是否要考虑 overflow
        int sumNumbers(TreeNode *root) {
            int sum = 0;
            int num = 0;
            sumNumbers(root, sum, num);
            return sum;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(7);
    cout << S->sumNumbers(root) << endl;
    return 0;
}

