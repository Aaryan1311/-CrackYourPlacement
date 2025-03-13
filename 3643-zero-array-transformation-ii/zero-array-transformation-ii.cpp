class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& q,int mid){
        int sum = 0;
        vector<int> arr(nums.size()+1,0);
        for(int i = 0;i<mid;i++){
            arr[q[i][0]] += q[i][2];
            arr[q[i][1]+1] -= q[i][2];
        }
        for(int i = 0;i<nums.size();i++){
            sum += arr[i];
            if(sum < nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0;
        int r = queries.size()-1;
        if(!check(nums,queries,queries.size())) return -1; 
        while(l <= r){
            int mid = l + (r-l)/2;
            bool pos = check(nums,queries,mid);
            if(pos) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};