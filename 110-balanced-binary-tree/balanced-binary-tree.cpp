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

    int height(TreeNode* node){
        if(node == nullptr) return 0;
        int l = height(node->left);
        int r = height(node->right);
        if(abs(r-l) >= 2) return 10000;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(height(root) >= 10000) return false;
        return true;
    }
};