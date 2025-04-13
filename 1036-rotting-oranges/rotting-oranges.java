class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<Pair> q = new LinkedList<>();
        int[][] vis = new int[grid.length][grid[0].length];
        for(int[] r : vis) Arrays.fill(r,-1);
        for(int i = 0;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
                if(grid[i][j] == 2){
                    q.add(new Pair(i,j,0));
                    vis[i][j] = 1;
                }
            }
        }
        int mintime = 0;
        while(!q.isEmpty()){
            Pair p = q.peek();
            int x = p.x;
            int y = p.y;
            int time = p.time;
            //top
            if(x != 0 && grid[x-1][y] == 1 && vis[x-1][y] == -1){
                vis[x-1][y] = 1;
                grid[x-1][y] = 2;
                q.add(new Pair(x-1,y,time+1));
            }
            //down
            if(x != grid.length-1 && grid[x+1][y] == 1 && vis[x+1][y] == -1){
                vis[x+1][y] = 1;
                grid[x+1][y] = 2;
                q.add(new Pair(x+1,y,time+1));
            }
            //left
            if(y != 0 && grid[x][y-1] == 1 && vis[x][y-1] == -1){
                vis[x][y-1] = 1;
                grid[x][y-1] = 2;
                q.add(new Pair(x,y-1,time+1));
            }
            //right
            if(y != grid[0].length-1 && grid[x][y+1] == 1 && vis[x][y+1] == -1){
                vis[x][y+1] = 1;
                grid[x][y+1] = 2;
                q.add(new Pair(x,y+1,time+1));
            }

            q.poll();
            mintime = Math.max(mintime,time);
        }

        for(int i = 0;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return mintime;
    }

    class Pair{
        int x;
        int y;
        int time;
        Pair(int x, int y, int time){
            this.x = x;
            this.y = y;
            this.time = time;
        }
    }
}