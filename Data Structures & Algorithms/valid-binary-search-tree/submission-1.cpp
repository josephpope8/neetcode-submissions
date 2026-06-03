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
    bool BST(TreeNode* root, int min, int max){
        if(!root){
            return true;
        }
        if(root->val < min || root->val > max){
            return false;
        }
        return BST(root->left, min, root->val - 1) && BST(root->right, root->val + 1, max);
    }
    bool isValidBST(TreeNode* root) {
        int max = numeric_limits<int>::max();
        int min = numeric_limits<int>::min();
        return BST(root, min, max);
    }
};
