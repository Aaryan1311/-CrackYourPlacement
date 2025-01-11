class Solution {
public:
    int helper(int idx, int sum, int tar, vector<int>& arr, map<pair<int,int>,int>& mp){
        if(idx == arr.size()){
            if(sum == tar) return 1;
            return 0;
        } 
        pair<int,int> p = {idx,sum};
        if(mp.find(p) != mp.end()) return mp[p];

        int add = helper(idx+1,sum + arr[idx], tar, arr,mp);
        int sub = helper(idx+1,sum - arr[idx],tar,arr,mp);

        int ans = add + sub;
        mp[p] = ans;
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int> mp;
        return helper(0,0,target,nums,mp);
    }
};