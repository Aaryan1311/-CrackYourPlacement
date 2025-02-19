class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> pre(n+1,0);
        pre[1] = nums[0];
        for(int i = 1;i<n;i++){
            pre[i+1] = pre[i] + nums[i];
        }
        int l = 1;
        int r = 1;
        long long ans = 0;
        while(l<= r && r <= n){
            long long sum = pre[r] - pre[l-1];
            int length = r-l+1;
            long long scr = sum*length;
            if(scr < k){
                // cout << l << " " << r << endl;
                ans += length;
                r++;
            }
            else{
                l++;
                if(l > r) r++;
            }
        }
        return ans;
    }
};