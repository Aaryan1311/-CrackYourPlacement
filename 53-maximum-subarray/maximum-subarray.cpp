class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = 0;
        int max_neg = INT_MIN;
        bool flag = false;
        int fs = -1;
        int fe = -1;
        int mxn = -1;
        int s = -1;
        int e = -1;
        for(int i = 0;i<nums.size();i++){
            if(sum == 0){
                s = i;
            }
            sum += nums[i];
            if(sum < 0){
                sum = 0;
                if(max_neg < nums[i]){
                    max_neg =  nums[i];
                    mxn = i;
                }
            }
            else{
                flag = true;
                if(max_sum < sum){
                    max_sum = sum;
                    fs = s;
                    fe = i;
                }
            }
        }
        
        if(max_sum == 0 && !flag) {
            cout << mxn << endl;
            return max_neg;
        }
        cout << fs << " " << fe << endl;
        return max_sum;
    }
};