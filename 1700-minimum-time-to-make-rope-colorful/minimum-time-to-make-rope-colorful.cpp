class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int l = 0;
        int r = 1;
        int ans = 0;
        while(r < colors.size()){
            if(colors[l] == colors[r]){
                if(neededTime[l] <= neededTime[r]){
                    ans += neededTime[l];
                    l = r;
                    r++;
                }
                else{
                    ans += neededTime[r];
                    r++;
                }
            }
            else{
                l = r;
                r++;
            }
        }
        return ans;
    }
};