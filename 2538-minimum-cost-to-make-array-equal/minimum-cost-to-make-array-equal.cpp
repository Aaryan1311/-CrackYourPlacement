class Solution {
public:
    long long helper(vector<int>& num, vector<int>& cost, int x) {
        long long res = 0;
        for (int i = 0; i < num.size(); i++) {
            res += 1LL * abs(x - num[i]) * cost[i];
        }
        return res;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        while (l < r) {
            int mid = l + (r - l) / 2;
            long long cost1 = helper(nums, cost, mid);
            long long cost2 = helper(nums, cost, mid + 1);
            if (cost1 < cost2) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return helper(nums, cost, l);
    }
};
