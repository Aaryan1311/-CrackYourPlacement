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
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        queue<TreeNode*> q;
        if(root == nullptr) return false;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                int val = node->val;
                if(s.find(k-val) != s.end()) return true;
                else{
                    s.insert(val);
                }
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);

                q.pop();
            }
        }
        return false;
    }
};