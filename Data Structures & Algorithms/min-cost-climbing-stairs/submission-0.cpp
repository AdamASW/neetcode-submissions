class Solution {
public:
    unordered_map<int,int> mp;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // mp[i] : min cost of stepping up to stair i.
        mp[0] = 0; // 1st stair.
        mp[1] = 0; // 2nd stair.
        for (int i = 2; i <= n; i++) {
            mp[i] = min({(cost[i-1] + mp[i-1]), (cost[i-2] + mp[i-2])});
        }
        return mp[n];
    }
};