class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = 0;
        int max_neg = INT_MIN;
        bool flag = false;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            if(sum < 0){
                sum = 0;
                max_neg = max(max_neg,nums[i]);
            }
            else{
                flag = true;
                max_sum = max(max_sum,sum);
            }
        }
        if(max_sum == 0 && !flag) return max_neg;
        return max_sum;
    }
};