class Solution {
public:
    set<vector<int>> seen = {};

    void twoSum(vector<int>& nums, vector<vector<int>>& triplets, int target, int i) {
        unordered_map<int, int> mp = {};
        for (int k = i + 1; k < nums.size(); k++) {
            int need = target - nums[k];
            if (mp.count(need)) {
                int j = mp[need];
                vector<int> curr_triplet = {nums[i], nums[j], nums[k]};
                sort(curr_triplet.begin(), curr_triplet.end());
                if (!seen.count(curr_triplet)) {
                    triplets.push_back(curr_triplet);
                    seen.insert(curr_triplet);
                }
            }
            mp[nums[k]] = k;
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSumTriplets = {};
        for (int i = 0; i < nums.size(); i++) {
            twoSum(nums, threeSumTriplets, (-nums[i]), i);
        }
        return threeSumTriplets;
    }
};