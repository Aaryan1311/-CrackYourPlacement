class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> arr(3,0);
        int l = 0;
        int ans = 0;
        int r = 0;
        while(r < s.size()){
            if(s[r] == 'a') arr[0]++;
            if(s[r] == 'b') arr[1]++;
            if(s[r] == 'c') arr[2]++;
            while(arr[0] > 0 && arr[1] > 0 && arr[2] > 0){
                ans += (s.size()-r);
                if(s[l] == 'a') arr[0]--;
                if(s[l] == 'b') arr[1]--;
                if(s[l] == 'c') arr[2]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};