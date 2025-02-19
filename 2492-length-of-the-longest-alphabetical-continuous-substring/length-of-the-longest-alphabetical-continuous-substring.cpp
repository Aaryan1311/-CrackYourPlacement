class Solution {
public:
    int longestContinuousSubstring(string s) {
        int cnt = 1;
        int mx = 0;
        for(int i = 0;i<s.size()-1;i++){
            if((s[i]-'a') == (s[i+1]-'a')-1) cnt++;
            else{
                mx = max(mx,cnt);
                cnt = 1;
            }
        }
        mx = max(mx,cnt);
        return mx;
    }
};