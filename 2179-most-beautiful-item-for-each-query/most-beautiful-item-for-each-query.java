class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        TreeMap<Integer,Integer> map = new TreeMap<>();
        for(int i = 0;i<items.length;i++){
            if(!map.containsKey(items[i][0])) map.put(items[i][0],items[i][1]);
            else  map.put(items[i][0],Math.max(items[i][1],map.get(items[i][0])));
        }
        int max = 0;
        TreeMap<Integer,Integer> finalmap = new TreeMap<>();
        finalmap.put(0,0);
        for(Map.Entry<Integer,Integer> e : map.entrySet()){
            max = Math.max(e.getValue(),max);
            finalmap.put(e.getKey(),max);
        }

        int ans[] = new int[queries.length];
        for(int i = 0;i<ans.length;i++){
            ans[i] = finalmap.get(finalmap.floorKey(queries[i]) == null ? 0 : finalmap.floorKey(queries[i]));
        }
        return ans;
    }
}