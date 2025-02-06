class Solution {
public:
    void dfs(int idx, vector<int>& vis, vector<vector<int>>& adj){
        vis[idx] = 1;
        for(int i = 0;i<adj[idx-1].size();i++){
            if(adj[idx-1][i] == 1 && vis[i+1] == 0){
                dfs(i+1,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        int cnt = 0;
        vector<int> vis(n+1,0);
        for(int i = 1;i<=n;i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};