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
    vector<int> inorder(TreeNode* node, vector<int>& ans){
        if(node == nullptr) return ans;
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        return inorder(root,ans);
    }
};