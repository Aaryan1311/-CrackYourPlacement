class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int arr[] = new int[k+1];
        Arrays.fill(arr,0);
        int sum = 0;
        for(int i = 0;i<nums.length;i++){
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0) rem += k;
            arr[rem]++;

        }
        int cnt = arr[0];
        for(int i = 0;i<k;i++){
           int x = (arr[i]*(arr[i]-1))/2;
           cnt += x;
        }
        return cnt;
    }
}