//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<int,int> mp;
        int mx = 0;
        long long sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum += arr[i];
            if(sum == k){
                mx = max(i+1,mx);
            }
            else{
                if(mp.find(sum) == mp.end()){
                    mp[sum] = i;
                }
                if(mp.find(sum-k) != mp.end()){
                    mx = max(mx,i - mp[sum-k]);
                }
            }
        }
        return mx;
    }
};

// 94 61 48 88 6 100 66 53 93 11

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends