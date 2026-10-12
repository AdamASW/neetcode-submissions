class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] : max money robbed for a row of the first i+1 houses.
        unordered_map<int,int> mp;
        int n = nums.size();
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max({nums[0], nums[1]});
        mp[0] = nums[0];
        mp[1] = max(nums[0],nums[1]);
        for (int i = 2; i < n; i++) {
            mp[i] = max(mp[i-1], nums[i] + mp[i-2]);
        }
        return mp[n-1];
    }
};