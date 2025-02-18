class Solution {
public:
    bool helper(int idx, int n, vector<int>& vis, vector<int>& ans){
        while(idx < ans.size() && ans[idx] != 0) idx++;
        if(idx == ans.size()) return true;
        for(int i = n;i>=1;i--){
            if(vis[i] == 1) continue;
            else{
                 if(i == 1){
                        vis[i] = 1;
                        ans[idx] = 1;
                        if(helper(idx+1,n,vis,ans)) return true;
                        vis[i] = 0;
                        ans[idx] = 0;
                    }
                    else{
                        if(idx + i < ans.size() && ans[idx + i] == 0){
                            vis[i] = 1;
                            ans[idx] = i;
                            ans[idx + i] = i;
                            if(helper(idx+1,n,vis,ans)) return true;
                            vis[i] = 0;
                            ans[idx] = 0;
                            ans[idx+i] = 0;
                        }
                    }
                }
            }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> vis(n+1,0);
        vector<int> ans(2*n-1,0);
        helper(0,n,vis,ans);
        return ans;
    }
};