class Solution {
public:
    void helper(int row, int col, vector<vector<int>>& arr){
        for(int i = 0;i<arr[0].size();i++){
            arr[row][i] = 0;
        }
        for(int j = 0;j<arr.size();j++){
            arr[j][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> v;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
               if(matrix[i][j] == 0) v.push_back({i,j});
            }
        }
        for(int i = 0;i<v.size();i++){
            helper(v[i].first,v[i].second,matrix);
        }
        return;
    }
};