class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = n-1;
        while(l < n-1){
            if(nums[l] < nums[l+1]) l++;
            else break;
        }
        if(l == n-1){
            long long nn = n;
            long long ans = (nn*(nn+1))/2;
            return ans;
        }
        while(r > l){
            if(nums[r] > nums[r-1]) r--;
            else break;
        }

        long long ans = 0;
        ans += (l+1);
        ans += (n-r);
        int first = 0;
        int last = r;
        while(first <= l && r < n){
            if(nums[first] < nums[r]){
                first++;
                ans += (n-r);
            }
            else{
                r++;
            }
        }
        return ans+1;

    }
};