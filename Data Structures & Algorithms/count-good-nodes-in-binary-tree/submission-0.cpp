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
    void count(TreeNode* node, int max, int& c){
        if(!node){
            return;
        }
        if(node->val >= max){
            c++;
            max = node->val;
        }
        count(node->left, max, c);
        count(node->right, max, c);
    }
    int goodNodes(TreeNode* root) {
        int c = 0;
        int max = -101;
        count(root, max, c);
        return c;
    }
};
