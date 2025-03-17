class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> arr(501,0);
        for(int i : nums){
            arr[i]++;
        }
        for(int i : arr){
            if(i%2) return false;
        }
        return true;
    }
};