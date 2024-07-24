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
    int max = Integer.MIN_VALUE;
    public int helper(TreeNode node){
        if(node == null) return 0;
        max = Math.max(node.val,max);
        int left = helper(node.left);
        int right = helper(node.right);
        int m = Math.max(left,right);
        max = Math.max(max,m + node.val);
        max = Math.max(max, left + right + node.val);
        return Math.max(m + node.val,node.val);
    }
    public int maxPathSum(TreeNode root) {
        helper(root);
        return max;
    }
}