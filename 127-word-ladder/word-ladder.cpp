class Solution {
public:
    int ladderLength(string b, string e, vector<string>& arr) {
        queue<pair<string,int>> q;
        q.push({b,1});
        vector<int> vis(arr.size(),-1);
        while(!q.empty()){
            pair<string,int> p = q.front();
            string s = p.first;
            int cnt = p.second;
            for(int i = 0;i<arr.size();i++){
                if(vis[i] == -1){
                    // cout << arr[i] << endl;
                    int diff = 0;
                    for(int j = 0;j<arr[i].size();j++){
                        if(arr[i][j] != s[j]) diff++;
                    }
                    if(diff == 1){
                        vis[i] = 1;
                        if(arr[i] == e) return cnt+1;
                        cout << arr[i] << endl;
                        q.push({arr[i],cnt+1});
                    }
                }
            }
            q.pop();
        }
        return 0;
    }
};