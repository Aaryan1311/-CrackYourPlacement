//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int idx,vector<int>& vis,vector<vector<int>>& adj){
        vis[idx] = 1;
        for(int i = 0;i<adj[idx-1].size();i++){
            if(adj[idx-1][i] == 1 && vis[i+1] != 1){
                dfs(i+1,vis,adj);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V+1,0);
        int cnt = 0;
        for(int i = 1;i<=V;i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends