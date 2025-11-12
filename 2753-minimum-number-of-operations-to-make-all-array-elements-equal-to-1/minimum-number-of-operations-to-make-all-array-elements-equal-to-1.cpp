class Solution {
public:
    int helper(vector<int>& nums){
        int mini = INT_MAX;
        bool b = true;
        for(int i = 0;i<nums.size()-1;i++){
            int val = nums[i];
            b = true;
           for(int j = i+1;j<nums.size() && b;j++){
                val = gcd(val,nums[j]);
                if(val == 1){
                    b = false;
                    mini = min(mini,j-i);
                } 
           }
        }

        for(int i = nums.size()-1;i>0;i--){
            int val = nums[i];
            b = true;
           for(int j = i-1;j>=0 && b;j--){
                val = gcd(val,nums[j]);
                if(val == 1){
                    b = false;
                    mini = min(mini,abs(j-i));
                }
           }
        }
        return mini == INT_MAX ? -1 : mini;
    }
    int minOperations(vector<int>& nums) {
        int ans = -1;
        int cnt = 0;
        for(int i : nums){
            if(i == 1) cnt++;
        }
        if(cnt != 0) return nums.size()-cnt;
        int x = helper(nums);
        if(x == -1){
            return ans;
        }
        else{
            return x + nums.size()-1; 
        }
    }
};