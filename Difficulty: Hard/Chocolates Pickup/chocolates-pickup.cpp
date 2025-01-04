//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int helper(int row, int rob1, int rob2, vector<vector<int>>& arr, vector<vector<vector<int>>>& dp){
        if(row == arr.size() || rob1 < 0 || rob2 < 0 || rob1 >= arr[0].size() || rob2 >= arr[0].size()) return 0;
        
        if(dp[row][rob1][rob2] != -1) return dp[row][rob1][rob2];
        
        // cout << row << " " << rob1 << " " << rob2 << endl;
        
        int mx = 0;
        
        for(int i = -1;i<=1;i++){
           for(int j = -1;j<=1;j++){
             if(rob1 != rob2)  mx = max(mx,helper(row+1,rob1+i,rob2+j,arr,dp) + arr[row][rob1] + arr[row][rob2]); 
             else mx = max(mx,helper(row+1,rob1+i,rob2+j,arr,dp) + arr[row][rob1]);
           }
        }
        
        return dp[row][rob1][rob2] = mx;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m+1, vector<int> (m+1,-1)));
        return helper(0,0,m-1,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends