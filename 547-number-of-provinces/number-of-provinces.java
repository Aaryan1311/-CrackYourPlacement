class Solution {
    public void dfs(int idx, int[] vis, int[][] arr){
        vis[idx] = 1;
        for(int i = 0;i<arr[idx].length;i++){
            if(arr[idx][i] == 1 && vis[i] == -1){
                dfs(i,vis,arr);
            }
        }
    }
    public int findCircleNum(int[][] arr) {
        int n = arr.length;
        int vis[] = new int[n];
        Arrays.fill(vis,-1);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(vis[i] == -1){
                dfs(i,vis,arr);
                cnt++;
            }
        }
        return cnt;
    }
}