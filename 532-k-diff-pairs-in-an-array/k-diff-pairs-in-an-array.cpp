class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        int cnt = 0;
        if(k){
            for(int i : nums){
                if(mp[i] != -1 && mp.find(i+k) != mp.end()) cnt++;
                mp[i] = -1;
            }
            return cnt;
        }
        for(int i : nums){
            if(mp[i] > 1) cnt++;
            mp[i] = -1;
        }
        return cnt;
    }
};