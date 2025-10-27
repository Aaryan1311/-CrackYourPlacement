class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long ans = 0;
        if(nums.size() == 1) return nums[0]*nums[0];
        for(int i = nums.size()-1;i>=nums.size()/2;i--){
            ans += nums[i]*nums[i];
        }
        for(int i =  nums.size()/2-1;i>=0;i--){
            ans -= nums[i]*nums[i];
        }
        return ans;
    }
};