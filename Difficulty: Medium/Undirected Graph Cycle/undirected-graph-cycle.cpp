//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        vector<int> vis(adj.size(),-1);
        for(int i = 0;i<vis.size();i++){
            if(vis[i] == -1){
            queue<pair<int,int>> q;
            q.push({i,-1});
            vis[i] = 1;
            while(!q.empty()){
            pair<int,int> p = q.front();
            int idx = p.first;
            int par = p.second;
            for(int i = 0;i<adj[idx].size();i++){
                if(vis[adj[idx][i]] == 1 && adj[idx][i] != par) return true;
                if(adj[idx][i] != par){
                    vis[adj[idx][i]] = 1;
                    pair<int,int> p = {adj[idx][i],idx};
                    q.push(p);
                }
            }
            q.pop();
        }
            }
        }
       
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends