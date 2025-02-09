class Solution {
public:
    bool dfs(int idx,int col, vector<int>& vis, vector<vector<int>>& adj){
        vis[idx] = col;
        for(int i : adj[idx]){
            if(vis[i] == col) return false;
            if(vis[i] == -1) if(!dfs(i,col == 1 ? 0 : 1,vis,adj)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
        for(int i = 0;i<vis.size();i++){
            if(vis[i] == -1) if(!dfs(i,1,vis,graph)) return false;
        }
        return true;
    }
};