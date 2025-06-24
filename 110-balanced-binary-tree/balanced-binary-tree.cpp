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
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        int left = height(root->left);
        int right = height(root->right);
        if(left == -1 || right == -1) return -1;
        if(abs(left - right) >= 2) return -1;
        return max(left+1,right+1);

    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int h = height(root);
        if(h == -1) return false;
        return true;
    }
};