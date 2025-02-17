class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt = 0;
        int neg = 0;
        int n = nums.size();
        for(int i : nums){
            if(i == 0) cnt++;
            if(i < 0) neg++;
        }
        if(cnt >= 2){
            vector<int> arr(nums.size(),0);
            return arr;
        }
        else{
            int prod = 1;
            for(int i : nums){
               if(i) prod *= i;
            }
            vector<int> ans(n);
            for(int i = 0;i<nums.size();i++){
                if(nums[i] && cnt == 1){
                    ans[i] = 0;
                }
                else if(cnt == 1){
                    ans[i] = prod;
                }
                else if(nums[i]){
                    ans[i] = prod/nums[i];
                }
            }
            return ans;
        }

    }
};