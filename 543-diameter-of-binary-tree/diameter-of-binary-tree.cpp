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
    int mx = 0;
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        int left = height(root->left);
        int right = height(root->right);
        mx = max(left+right,mx);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return mx;
    }
};