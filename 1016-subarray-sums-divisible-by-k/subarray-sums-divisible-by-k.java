class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer,Integer> mp = new HashMap<>();
        int sum = 0;
        int ans = 0;
        mp.put(0,1);
        for(int i = 0;i<nums.length;i++){
            sum += nums[i];
            int rem = sum%k;
            if(rem < 0) rem += k;
            if(mp.containsKey(rem)) {
                ans += mp.get(rem);
                mp.put(rem,mp.get(rem)+1);
            }
            else mp.put(rem,1);
        }
        return ans;
    }
}