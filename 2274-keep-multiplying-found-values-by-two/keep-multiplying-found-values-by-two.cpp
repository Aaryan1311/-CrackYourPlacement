class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        // int idx = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == original){
                // nums[i] = original*2;
                original = 2*original;
                // idx = i;
                i = -1;
            }
        }
        return original;
    }
};