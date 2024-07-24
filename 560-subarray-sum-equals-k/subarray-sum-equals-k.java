class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int arr[] = new int[n];
        arr[0] = nums[0];
        for(int i = 1;i<n;i++){
            arr[i] = nums[i] + arr[i-1];
        }
        Map<Integer,Integer> mp = new HashMap<>();
        mp.put(0,1);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            int comp = arr[i] - k;
            if(mp.containsKey(comp)) cnt += mp.get(comp);
            if(mp.containsKey(arr[i])){
                mp.put(arr[i],mp.get(arr[i])+1);
            }
            else mp.put(arr[i],1);
        }
        return cnt;
    }
}