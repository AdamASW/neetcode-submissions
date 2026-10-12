class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] but with two arrays, ignoring the first house and one ignoring the last house. Return
        // the max between the two. We had to do two arrays because there was no easy way to encode.
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);
        if (nums.size() == 3) return max({nums[0],nums[1],nums[2]});

        mp1[0] = nums[0];
        mp2[0] = nums[1];
        mp1[1] = max(mp1[0],nums[1]);
        mp2[1] = max(mp2[0],nums[2]);

        int n = nums.size();
        int j = 3;
        for (int i = 2; i < n-1; i++) {
            mp1[i] = max(mp1[i-1], nums[i] + mp1[i-2]);
            mp2[i] = max(mp2[i-1], nums[j] + mp2[i-2]);
            j++;
        }

        return max(mp1[n-2],mp2[n-2]);
    }
};
