class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int mx = INT_MIN;
        int idx = -1;
        for(int i=0;i<nums.size();i++){
            if(mx <= nums[i]){
                mx = nums[i];
                idx = i;
            }
        }
        return idx;
    }
};