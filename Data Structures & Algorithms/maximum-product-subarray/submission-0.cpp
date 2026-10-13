class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // dp[i]: maximum product seen up to element i.
        // Record the
        unordered_map<int,int> max_mp;
        unordered_map<int,int> min_mp;
        int n = nums.size();
        int global_max = -INT_MAX;
        max_mp[0] = nums[0];
        min_mp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            max_mp[i] = max({nums[i]*max_mp[i-1], nums[i]*min_mp[i-1], nums[i]});
            global_max = (global_max < max_mp[i]) ? max_mp[i] : global_max;
            min_mp[i] = min({nums[i]*max_mp[i-1], nums[i]*min_mp[i-1], nums[i]});
        }
        return (global_max < max_mp[n-1]) ? max_mp[n-1] : global_max;
    }
};