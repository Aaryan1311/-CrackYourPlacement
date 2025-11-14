class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> arr(n, vector<int> (n,0));
        for(int i = 0;i<queries.size();i++){
            for(int j = queries[i][0];j<=queries[i][2];j++){
                for(int k = queries[i][1];k<=queries[i][3];k++){
                    arr[j][k]++;
                }
            }
        }
        return arr;
    }
};