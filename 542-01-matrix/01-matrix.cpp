class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(),-1));
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            pair<int,int> p = q.front().first;
            int i = p.first;
            int j = p.second;
            int dis = q.front().second;
            //top
            if(i != 0 && vis[i-1][j] == -1){
                if(mat[i-1][j] == 1){
                    pair<int,int> pp = {i-1,j};
                    q.push({pp,dis+1});
                    ans[i-1][j] = dis+1;
                    vis[i-1][j] = 1;
                }
            }
            //down
             if(i != mat.size()-1 && vis[i+1][j] == -1){
                if(mat[i+1][j] == 1){
                    pair<int,int> pp = {i+1,j};
                    q.push({pp,dis+1});
                    ans[i+1][j] = dis+1;
                    vis[i+1][j] = 1;
                }
            }
            //left
             if(j != 0 && vis[i][j-1] == -1){
                if(mat[i][j-1] == 1){
                    pair<int,int> pp = {i,j-1};
                    q.push({pp,dis+1});
                    ans[i][j-1] = dis+1;
                    vis[i][j-1] = 1;
                }
            }
            //right
            if(j != mat[0].size()-1 && vis[i][j+1] == -1){
                if(mat[i][j+1] == 1){
                    pair<int,int> pp = {i,j+1};
                    q.push({pp,dis+1});
                    ans[i][j+1] = dis+1;
                    vis[i][j+1] = 1;
                }
            }
            q.pop();
        }
        return ans;
    }
};