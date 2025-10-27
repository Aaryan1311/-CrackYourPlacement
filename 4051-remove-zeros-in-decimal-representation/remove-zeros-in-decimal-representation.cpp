class Solution {
public:
    long long removeZeros(long long n) {
        string s = "";
        while(n>0){
            int x = n%10;
            if(x) s += to_string(x);
            n/=10;
        }
        reverse(s.begin(),s.end());
        long long xx = stoll(s);
        return xx;
    }
};