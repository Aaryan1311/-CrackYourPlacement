/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int max = 0;
    public int helper(TreeNode node){
        if(node == null) return 0;
        if(node.left == null && node.right == null) return 1;
        int left = helper(node.left);
        int right = helper(node.right);
        max = Math.max(max,left+right);
        return Math.max(left,right)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        helper(root);
        return max;
    }
}