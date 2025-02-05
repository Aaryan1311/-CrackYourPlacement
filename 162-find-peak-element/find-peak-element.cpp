class Solution {
public:
    int shiksha(int l, int r, vector<int>& nums){
            int mid = l + (r-l)/2;
            if(mid != 0 && mid != nums.size()-1){
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
                else{
                    if(nums[mid] < nums[mid+1] && nums[mid] > nums[mid-1]){
                        return shiksha(mid,r,nums);
                    }
                    else if(nums[mid] > nums[mid+1] && nums[mid] < nums[mid-1]){
                        return shiksha(l,mid,nums);
                    }
                    else{
                        return shiksha(l,mid,nums);
                    }
                }
            }

            else if(mid == 0 && nums[mid+1] < nums[mid]) return mid;
            else if(mid == nums.size()-1 && nums[mid] > nums[mid-1]) return mid;

            return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
        return shiksha(l,r,nums);
    }
};