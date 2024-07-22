class Solution {
    public int maxProfit(int[] prices) {
        int curr = 0;
        int min = Integer.MAX_VALUE;
        int max = 0;
        for(int i = 0;i<prices.length;i++){
            min = Math.min(min,prices[i]);
            curr = prices[i] - min;
            max = Math.max(max,curr);
        }
        return max;
    }
}