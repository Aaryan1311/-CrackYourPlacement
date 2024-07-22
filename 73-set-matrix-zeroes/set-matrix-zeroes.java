class Solution {
    public void helper(int arr[][], int k){
        for(int i = 0;i<arr[0].length;i++){
            arr[k][i] = 0;
        }
    }
    public void helper2(int arr[][], int k){
        for(int i = 0;i<arr.length;i++){
            arr[i][k] = 0;
        }
    }
    public void setZeroes(int[][] matrix) {
        List<Integer> r = new ArrayList<>();
        List<Integer> c = new ArrayList<>();
        for(int i = 0;i<matrix.length;i++){
            for(int j =0;j<matrix[0].length;j++){
                if(matrix[i][j] == 0){
                    if(!r.contains(i)) r.add(i);
                    if(!c.contains(j)) c.add(j);
                }
            }
        }
        for(int i = 0;i<r.size();i++){
            helper(matrix,r.get(i));
        }
        for(int i = 0;i<c.size();i++){
            helper2(matrix,c.get(i));
        }
        return;
    }
}