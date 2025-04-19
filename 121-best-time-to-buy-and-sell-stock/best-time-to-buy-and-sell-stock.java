class Solution {
    public int maxProfit(int[] prices) {
        int cp = Integer.MAX_VALUE;
        int prof = 0;
        for(int i = 0;i<prices.length;i++){
            prof = Math.max(prices[i] - cp,prof);
            cp = Math.min(cp,prices[i]);
        }
        return prof;
    }
}