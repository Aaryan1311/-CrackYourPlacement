//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int idx, vector<int>& vis,vector<vector<int>>& adj,vector<int>& v){
        vis[idx] = 1;
        v.push_back(idx);
        for(int i = 0;i<adj[idx].size();i++){
            if(vis[adj[idx][i]] == 0){
                dfs(adj[idx][i],vis,adj,v);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        vector<int> v;
        vector<int> vis(adj.size(),0);
        for(int i = 0;i<vis.size();i++){
            if(vis[i] == 0){
                dfs(i,vis,adj,v);
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends