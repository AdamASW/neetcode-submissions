class Solution {
public:
    bool canJump(vector<int>& nums) {
        // dp[i] can we reach idx i from the beginning of nums?
        int n = nums.size();
        vector<int> dp(n, false);
        dp[0] = true;

        for (int i = 0; i < n-1; i++) {
            if (dp[i] == false) return false; // haven't been able to reach.
            for (int jump = 0; (jump <= nums[i]) && (i+jump < n); jump++) {
                dp[i+jump] = true;
            }
        }

        return dp[n-1];
    }
};
