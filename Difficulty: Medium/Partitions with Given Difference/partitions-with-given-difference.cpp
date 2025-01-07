//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int helper(int idx, int sum, int diff, int total, vector<int> & arr, vector<vector<int>>& dp){
        if(idx == arr.size()){
            if(abs(total -2*sum) == diff) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        int choose = helper(idx+1,sum+arr[idx],diff,total,arr,dp);
        int notchoose = helper(idx+1,sum,diff,total,arr,dp);
        
        return dp[idx][sum] = choose + notchoose;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum = 0;
        for(int i : arr) sum += i;
        vector<vector<int>> dp(arr.size(), vector<int> (sum+1,-1));
        int ans =  helper(0,0,d,sum,arr,dp);
        if(d == 0) return ans;
        else return ans/2;
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends