#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            vector<pair<int, int>> elems;
            for (auto& p : freq) {
                elems.push_back({p.second, p.first});
            }
            sort(elems.begin(), elems.end(), [&](auto& a, auto& b) {
                if (a.first == b.first) return a.second > b.second;
                return a.first > b.first;
            });

            long long sum = 0;
            for (int t = 0; t < min(x, (int)elems.size()); t++) {
                sum += 1LL * elems[t].first * elems[t].second;
            }
            ans.push_back((int)sum);
        }

        return ans;
    }
};
