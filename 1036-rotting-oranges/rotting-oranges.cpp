class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),-1));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    pair<int,int> c = {i,j};
                    pair<pair<int,int>,int> p = {c,0};
                    q.push(p);
                }
            }
        }
        int max_time = 0;
        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            int curr_time = p.second;
            int i = p.first.first;
            int j = p.first.second;
            //top
            if(i != 0 && vis[i-1][j] == -1){
                if(grid[i-1][j] == 1){
                    pair<int,int> c = {i-1,j};
                    pair<pair<int,int>,int> p = {c,curr_time+1};
                    q.push(p);
                    vis[i-1][j] = 1;
                    grid[i-1][j] = 2;
                }
            }
            //down
            if(i != grid.size()-1 && vis[i+1][j] == -1){
                if(grid[i+1][j] == 1){
                    pair<int,int> c = {i+1,j};
                    pair<pair<int,int>,int> p = {c,curr_time+1};
                    q.push(p);
                    vis[i+1][j] = 1;
                    grid[i+1][j] = 2;
                }
            }
            //left
            if(j != 0 && vis[i][j-1] == -1){
                if(grid[i][j-1] == 1){
                    pair<int,int> c = {i,j-1};
                    pair<pair<int,int>,int> p = {c,curr_time+1};
                    q.push(p);
                    vis[i][j-1] = 1;
                    grid[i][j-1] = 2;
                }
            }
            //right
            if(j != grid[0].size()-1 && vis[i][j+1] == -1){
                if(grid[i][j+1] == 1){
                    pair<int,int> c = {i,j+1};
                    pair<pair<int,int>,int> p = {c,curr_time+1};
                    q.push(p);
                    vis[i][j+1] = 1;
                    grid[i][j+1] = 2;
                }
            }
            max_time =  max(max_time,curr_time);
            q.pop();
        }

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return max_time;
    }
};