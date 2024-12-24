class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items,(a,b) -> a[0] - b[0]);
        int max = 0;
        for(int i[] : items){
            max = Math.max(i[1],max);
            i[1] = max;
        }
        int res[] = new int[queries.length];
        for(int i = 0;i<queries.length;i++){
            int l = 0;
            int r = items.length-1;
            int ans = 0;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(items[mid][0] <= queries[i]){
                    ans = items[mid][1];
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            res[i] = ans;
        }
        return res;
    }
}