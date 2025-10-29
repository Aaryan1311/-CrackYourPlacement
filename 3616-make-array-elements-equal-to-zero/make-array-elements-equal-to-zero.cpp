class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int cnt = 0;
        vector<int> pre(nums.size());
        vector<int> suf(nums.size());
        pre[0] = nums[0];
        suf[nums.size()-1] = nums[nums.size()-1];
        for(int i = 1;i<nums.size();i++){
            pre[i] = nums[i]+pre[i-1];
        }
        for(int i = nums.size()-2;i>=0;i--){
            suf[i] = suf[i+1]+nums[i];
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                if(pre[i] == suf[i]) cnt+=2;
                else if(abs(pre[i]-suf[i]) == 1) cnt++;
            }
        }
        return cnt;
    }
};