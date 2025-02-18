class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<int> high(nums.size());
        high[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            high[i] = max(high[i-1],nums[i]);
        }
        vector<long long> conver(nums.size());
        for(int i = 0; i < nums.size(); i++){
            conver[i] = high[i] + nums[i];
        }
        vector<long long> ans(nums.size());
        long long sum = 0;
        for(int i = 0;i<ans.size();i++){
            sum += conver[i];
            ans[i] = sum;
        }
        return ans;
    }
};