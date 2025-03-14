class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& q, int k){
        int sum = 0;
        vector<int> diff(nums.size()+1,0);
        for(int i = 0;i<k;i++){
            diff[q[i][0]] += q[i][2];
            diff[q[i][1]+1] -= q[i][2];
        }
        for(int i = 0;i<nums.size();i++){
            sum += diff[i];
            if(sum < nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int l = 0;
        int r = q.size()-1;
        if(!check(nums,q,q.size())) return -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(nums,q,mid)){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};