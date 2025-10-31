class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int> mp;
        vector<int> arr(2);
        int idx = 0;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1) {
                arr[idx] = nums[i]; 
                idx++;
            }
        }
        return arr;
    }
};