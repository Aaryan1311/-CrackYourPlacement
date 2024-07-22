class Solution {
    public int findDuplicate(int[] arr) {
       Set<Integer> s = new HashSet<>();
       for(int i = 0;i<arr.length;i++){
        if(s.contains(arr[i])) return arr[i];
        else s.add(arr[i]);
       }
       return -1;
    }
}