class Solution {
public:

    void nextPermutation(vector<int>& arr) {
        int idx = -1;
        int n = arr.size();
        for(int i = n-2;i>=0 && idx == -1;i--){
            if(arr[i] < arr[i+1]){  
                idx = i;
            }
        }
        if(idx == -1){
            reverse(arr.begin(),arr.end());
            return;
        }
        bool flag = true;
        for(int i = n-1;i>=0 && flag;i--){
            if(arr[idx] < arr[i]){
                int temp = arr[idx];
                arr[idx] = arr[i];
                arr[i] = temp;
                flag = false;
            }
            
        }
        reverse(arr.begin() + idx+1,arr.end());
        return;
    }
};