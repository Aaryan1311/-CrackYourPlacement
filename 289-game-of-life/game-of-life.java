class Solution {
    public int check(int arr[][], int i, int j){
        int ans = 0;
        if(i > 0){
            if(arr[i-1][j] == 1) ans++;
            if(j > 0){
                if(arr[i-1][j-1] == 1) ans++;
            }
            if(j < arr[0].length-1){
                if(arr[i-1][j+1] == 1) ans++;
            }
        }

        if(i < arr.length-1){
            if(arr[i+1][j] == 1) ans++;
            if(j != 0){
                if(arr[i+1][j-1] == 1) ans++;
            }
            if(j != arr[0].length-1){
                if(arr[i+1][j+1] == 1) ans++;
            }
        }

        if(j > 0){
            if(arr[i][j-1] == 1) ans++;
        }
        if(j < arr[0].length-1){
            if(arr[i][j+1] == 1) ans++;
        }
            return ans;
    }
    
    public void gameOfLife(int[][] board) {
        int arr[][] = new int[board.length][board[0].length];
        for(int i = 0;i<board.length;i++){
            for(int j = 0;j<board[0].length;j++){
                arr[i][j] = board[i][j];
            }
        }

        for(int i = 0;i<board.length;i++){
            for(int j = 0;j<board[0].length;j++){
                if(arr[i][j] == 0){
                    int cnt = check(arr,i,j);
                    // System.out.print(cnt + " ");
                    if(cnt == 3) board[i][j] = 1;
                }
                else{
                    int cnt = check(arr,i,j);
                    if(cnt < 2) board[i][j] = 0;
                    else if(cnt >=2 && cnt <= 3) board[i][j] = 1;
                    else board[i][j] = 0;
                }
            }
            System.out.println();
        }
    }
}