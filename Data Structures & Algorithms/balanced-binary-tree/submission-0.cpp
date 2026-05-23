/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int helper(TreeNode* root, bool& test){
        if(!root){
            return 0;
        }
        int l = 1 + helper(root->left, test);
        int r = 1 + helper(root->right, test);
        if(abs(l - r) > 1){
            test = false;
        }
        return max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        bool t = true;
        helper(root, t);
        return t;
    }
};
