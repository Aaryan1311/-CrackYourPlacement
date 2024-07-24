class Solution {
    public int[] twoSum(int[] nums, int target) {
        int arr[] = new int[2];
        Map<Integer,Integer> mp = new HashMap<>();
        for(int i = 0;i<nums.length;i++){
            int comp = target - nums[i];
            if(mp.containsKey(comp)){
                arr[0] = i;
                arr[1] = mp.get(comp); 
                return arr;
            }
            else mp.put(nums[i],i);
        }
        return arr;
    }
}