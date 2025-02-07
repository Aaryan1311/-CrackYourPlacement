class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(), vector<int> (board[0].size(),-1));
        queue<pair<int,int>> q;
        for(int i = 0;i<board.size();i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(board[i][board[0].size()-1] == 'O'){
                q.push({i,board[0].size()-1});
                vis[i][board[0].size()-1] = 1;
            }
        }
        for(int j = 0;j<board[0].size();j++){
            if(board[0][j] == 'O'){
                q.push({0,j});
                vis[0][j] = 1;
            }
            if(board[board.size()-1][j] == 'O'){
                q.push({board.size()-1,j});
                vis[board.size()-1][j] = 1;
            }
        }

        while(!q.empty()){
            pair<int,int> p = q.front();
            int i = p.first;
            int j = p.second;
            //top
            if(i != 0 && vis[i-1][j] == -1 && board[i-1][j] == 'O'){
                q.push({i-1,j});
                vis[i-1][j] = 1;
            }
            //down
            if(i != board.size()-1 && vis[i+1][j] == -1 && board[i+1][j] == 'O'){
                q.push({i+1,j});
                vis[i+1][j] = 1;
            }
            //left
            if(j != 0 && vis[i][j-1] == -1 && board[i][j-1] == 'O'){
                q.push({i,j-1});
                vis[i][j-1] = 1;
            }
            //right
            if(j != board[0].size()-1 && vis[i][j+1] == -1 && board[i][j+1] == 'O'){
                q.push({i,j+1});
                vis[i][j+1] = 1;
            }
            q.pop();
        }

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == 'O' && vis[i][j] != 1){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};