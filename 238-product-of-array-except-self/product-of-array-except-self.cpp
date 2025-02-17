class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> arr(nums.size());
        arr[0] = 1;
        for(int i = 1;i<nums.size();i++){
            arr[i] = arr[i-1]*nums[i-1];
        }
        int r = 1;
        for(int i = nums.size()-1;i>=0;i--){
            arr[i] *= r;
            r *= nums[i];
        }
        return arr;
    }
};
