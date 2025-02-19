class Solution {
public:
    int bs(vector<long long>& pre, int val){
        int l = 0;
        int r = pre.size()-1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r)/2;
            if(pre[mid] == val){
                ans = mid;
                l = mid+1;
            } 
            else if(pre[mid] < val){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<long long> pre(n);
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            pre[i] = sum;
        }
        for(long long i : pre) cout << i << " ";
        cout << endl;
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0;i<m;i++){
            int x = bs(pre,queries[i]);
            ans[i] = x+1;
        }
        return ans;
    }
};