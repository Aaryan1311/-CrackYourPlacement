class Solution {
public:
    long long coloredCells(int n) {
        return (4*((long long)n*((long long)n-1)/2)+1);
    }
};