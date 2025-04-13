class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int curr = image[sr][sc];
        Queue<Pair> q = new LinkedList();
        q.add(new Pair(sr,sc));
        image[sr][sc] = color;
        int [][] vis = new int[image.length][image[0].length];
        vis[sr][sc] = 1;
        for(int[] r : vis) Arrays.fill(r,-1);
        while(!q.isEmpty()){
            Pair p = q.peek();
            int x = p.x;
            int y = p.y;
            //top
            if(x != 0 && vis[x-1][y] == -1 && image[x-1][y] == curr){
                vis[x-1][y] = 1;
                image[x-1][y] = color;
                q.add(new Pair(x-1,y));
            }
            //down
            if(x != image.length-1 && vis[x+1][y] == -1 && image[x+1][y] == curr){
                vis[x+1][y] = 1;
                image[x+1][y] = color;
                q.add(new Pair(x+1,y));
            }
            //left
            if(y != 0 && vis[x][y-1] == -1 && image[x][y-1] == curr){
                vis[x][y-1] = 1;
                image[x][y-1] = color;
                q.add(new Pair(x,y-1));
            }
            //right
            if(y != image[0].length-1 && vis[x][y+1] == -1 && image[x][y+1] == curr){
                vis[x][y+1] = 1;
                image[x][y+1] = color;
                q.add(new Pair(x,y+1));
            }
            q.poll();
        }
        return image;
    }
    class Pair{
        int x;
        int y;
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}