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
class Pair{
    TreeNode node;
    int idx;
    Pair(TreeNode node, int idx){
        this.node = node;
        this.idx = idx;
    }
}
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        int ans = 0;
        Queue<Pair> q = new LinkedList();
        Pair r = new Pair(root,0);
        q.offer(r);
        while(!q.isEmpty()){
            int size = q.size();
            int first = -1;
            int last = -1;
            for(int i = 0;i<size;i++){
                if(i == 0) first = q.peek().idx;
                if(i == size-1) last = q.peek().idx;
                if(q.peek().node.left != null) {
                    Pair p = new Pair(q.peek().node.left,q.peek().idx*2+1);
                    q.offer(p);
                }
                if(q.peek().node.right != null) {
                    Pair p = new Pair(q.peek().node.right,q.peek().idx*2+2);
                    q.offer(p);
                }
                q.poll();
            }
            ans = Math.max(ans,last - first +1);
        }
        return ans;
    }
}