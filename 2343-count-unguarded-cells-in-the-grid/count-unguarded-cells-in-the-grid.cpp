class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> arr(m, vector<int> (n,0));
        for(int i =0;i<walls.size();i++){
            arr[walls[i][0]][walls[i][1]] = 1;
        }
        for(int i =0;i<guards.size();i++){
            arr[guards[i][0]][guards[i][1]] = 3;
        }
        for(int i = 0;i<guards.size();i++){
            // up
            bool b = true;
            for(int j = guards[i][0]-1; j>=0 && b;j--){
                if(arr[j][guards[i][1]] == 0) arr[j][guards[i][1]] = 2;
                else if(arr[j][guards[i][1]] == 1 || arr[j][guards[i][1]] == 3) b = false;
            }
             // down
             b = true;
            for(int j = guards[i][0]+1; j<m && b;j++){
                 if(arr[j][guards[i][1]] == 0) arr[j][guards[i][1]] = 2;
                else if(arr[j][guards[i][1]] == 1 || arr[j][guards[i][1]] == 3) b = false;
            }
            // left
            b = true;
            for(int j = guards[i][1]+1; j<n && b;j++){
                if(arr[guards[i][0]][j] == 0) arr[guards[i][0]][j] = 2;
                else if(arr[guards[i][0]][j] == 1 || arr[guards[i][0]][j] == 3) b = false;
            }
            b = true;
            // right
            for(int j = guards[i][1]-1; j>=0 && b;j--){
                if(arr[guards[i][0]][j] == 0) arr[guards[i][0]][j] = 2;
                else if(arr[guards[i][0]][j] == 1 || arr[guards[i][0]][j] == 3) b = false;
            }
        }

        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(arr[i][j] == 0) cnt++;
                // cout << arr[i][j] << ' ';
            }
            // cout << endl;
        }
        return cnt;
    }
};