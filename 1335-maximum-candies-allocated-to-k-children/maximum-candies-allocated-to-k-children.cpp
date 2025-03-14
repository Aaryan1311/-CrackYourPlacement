class Solution {
public:
    bool check(vector<int>& c, long long k, int mid){
        long long  cnt = 0;
        for(int i : c){
           if(mid != 0) cnt += i/mid;
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int>& c, long long k) {
        int mx = 0;
        for(int i : c){
            mx = max(i,mx);
        }
        int l = 1;
        int r = mx;
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(c,k,mid)){
                l = mid+1;
                ans = max(ans,mid);
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};