class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ic = image[sr][sc];
        if(ic == color) return image;
        queue<pair<int,int>> q;
        pair<int,int> c = {sr,sc};
        q.push(c);
        image[sr][sc] = color;
        while(!q.empty()){
            pair<int,int> p = q.front();
            int i = p.first;
            int j = p.second;
            //top
            if(i != 0 && image[i-1][j] == ic){
                image[i-1][j] = color;
                pair<int,int> p = {i-1,j};
                q.push(p); 
            }
            //down
            if(i != image.size()-1 && image[i+1][j] == ic){
                image[i+1][j] = color;
                pair<int,int> p = {i+1,j};
                q.push(p); 
            }
            //left
            if(j != 0 && image[i][j-1] == ic){
                image[i][j-1] = color;
                pair<int,int> p = {i,j-1};
                q.push(p); 
            }
            //right
            if(j != image[0].size()-1 && image[i][j+1] == ic){
                image[i][j+1] = color;
                pair<int,int> p = {i,j+1};
                q.push(p); 
            }
            q.pop();
        }
        return image;
    }
};