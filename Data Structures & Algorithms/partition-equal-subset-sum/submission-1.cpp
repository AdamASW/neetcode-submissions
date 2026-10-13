class Solution {
public:

    bool canPartition(vector<int>& nums) {
        // Can I pick some amount of distinct elements such that their sum is half the full array sum?
        int sum = accumulate(nums.begin(),nums.end(),0);
        if ((sum % 2) != 0) return false;
        int t = (sum / 2);

        // dp[s] : store if a sum s is achievable as we process elements:
        vector<bool> mp(t, false);

        mp[0] = true;
        for (int num : nums) {
            for (int s = t; s >= num; s--) {
                mp[s] = mp[s] || mp[s-num];
            }
        }
        return mp[t];
    }
};
