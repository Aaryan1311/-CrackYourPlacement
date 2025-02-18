class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        int val = 0;
        int n = nums.size();
        while(idx < nums.size()){
            if(n-idx == val) return val;
            int x = nums[idx];
            while(idx < nums.size() && x == val && x == nums[idx]) idx++;
            val++;
        }
        return -1;
    }
};