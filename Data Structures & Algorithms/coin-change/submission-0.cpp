class Solution {
public:
    int coinChangeDfs(vector<int>&coins, auto& mp, int current) {
        if (current < 0) return -1;
        if (current == 0) return 0;
        if (mp.count(current)) return mp[current];

        int best = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int result = coinChangeDfs(coins, mp, current - coins[i]);
            if (result != -1) best = min(best, result);
        }

        mp[current] = (best == INT_MAX) ? -1 : 1 + best;
        return mp[current];
    }

    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = amount of coins needed to get to a value i, -1 if impossible.
        unordered_map<int,int> mp;
        mp[amount] = coinChangeDfs(coins, mp, amount);
        return mp[amount];
    }
};