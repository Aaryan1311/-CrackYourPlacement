class Solution {
public:
    set<int> s;
    int helper(int n){
        int sum = 0;
        while(n >= 1){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        while(n != 1 && !s.contains(n)){
            s.insert(n);
            // cout << n << endl;
            n = helper(n);
        }
        return n == 1;
    }
};