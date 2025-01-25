class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int cp = INT_MAX;
        int sp = 0;
        for(int i = 0;i<prices.size();i++){
            if(cp > prices[i]) {
                cp = prices[i];
                sp = 0;
            }
            sp = max(sp,prices[i]);
            profit = max(profit,sp-cp);
        }
        return profit;
    }
};