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
    int mx = INT_MIN;
    int helper(TreeNode* node){
        if(node->left == nullptr && node->right == nullptr) return node->val;
        int left = -100000000;
        int right = -100000000;
       if(node->left != nullptr)  left = helper(node->left);
       if(node->right != nullptr) right = helper(node->right);
        mx = max(left,mx);
        mx = max(right,mx);
        mx = max(node->val,mx);
        mx = max(left+right+node->val,mx);
        return max(0,max(left,right)) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        mx = max(helper(root),mx);
        return mx;
    }
};