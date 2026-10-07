class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Stores the product prefix up to i.
        unordered_map<int,int> prefix_mp;
        unordered_map<int,int> suffix_mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prefix_mp[0] = 1;
                suffix_mp[n-1] = 1;
                continue;
            }
            prefix_mp[i] = prefix_mp[i-1]*nums[i-1];
            suffix_mp[n-1-i] = suffix_mp[n-i]*nums[n-i];
        }
        vector<int> answer = {};
        for (int i = 0; i < n; i++) {
            answer.push_back(prefix_mp[i]*suffix_mp[i]);
        }
        return answer;
    }
};
