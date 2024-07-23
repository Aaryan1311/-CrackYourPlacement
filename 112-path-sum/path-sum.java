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
    public boolean helper(int rem, TreeNode node){
        if(node == null) return false;
        if(node.left == null && node.right == null && rem == node.val) return true;
        if(node.left == null && node.right == null  && rem != node.val) return false;
        // if(Math.abs(rem) < Math.abs(node.val)) return false;
        return helper(rem-node.val,node.left) || helper(rem-node.val,node.right); 
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return helper(targetSum,root);
    }
}