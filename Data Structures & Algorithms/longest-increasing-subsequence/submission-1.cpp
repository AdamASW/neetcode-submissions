class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Decision: 
        // dp[i] : length of LIS up to and including index i.
        vector<int> mp(nums.size(), 1);
        int n = nums.size();

        for (int i = 1; i < nums.size(); i++) {
            int best = INT_MIN;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) best = max(best, mp[j]);
            }
            mp[i] = (best == INT_MIN) ? 1 : 1 + best;
        }
        return *max_element(mp.begin(), mp.end());
    }
};
