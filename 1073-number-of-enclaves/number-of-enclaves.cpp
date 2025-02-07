class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(),-1));
        queue<pair<int,int>> q;
        for(int i = 0;i<grid.size();i++){
            if(grid[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(grid[i][grid[0].size()-1] == 1){
                q.push({i,grid[0].size()-1});
                vis[i][grid[0].size()-1] = 1;
            }
        }   
        for(int j = 0;j<grid[0].size();j++){
            if(grid[0][j] == 1){
                q.push({0,j});
                vis[0][j] = 1;
            }
            if(grid[grid.size()-1][j] == 1){
                q.push({grid.size()-1,j});
                vis[grid.size()-1][j] = 1;
            }
        }

        while(!q.empty()){
            pair<int,int> p = q.front();
            int i = p.first;
            int j = p.second;
            //top 
            if(i != 0 && grid[i-1][j] == 1 && vis[i-1][j] == -1){
                q.push({i-1,j});
                vis[i-1][j] = 1;
            }
            //down
             if(i != grid.size()-1 && grid[i+1][j] == 1 && vis[i+1][j] == -1){
                q.push({i+1,j});
                vis[i+1][j] = 1;
            }
            //left
             if(j != 0 && grid[i][j-1] == 1 && vis[i][j-1] == -1){
                q.push({i,j-1});
                vis[i][j-1] = 1;
            }
            //right
             if(j != grid[0].size()-1 && grid[i][j+1] == 1 && vis[i][j+1] == -1){
                q.push({i,j+1});
                vis[i][j+1] = 1;
            }
            q.pop();
        }
        int cnt = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1 && vis[i][j] == -1) cnt++;
            }
        }
        return cnt;
    }
};