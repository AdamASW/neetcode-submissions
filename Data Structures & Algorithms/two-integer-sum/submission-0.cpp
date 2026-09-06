class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> idx_sol_map;
        for (int i = 0; i < nums.size(); i++) {
            int curr_need = target - nums[i];
            if (idx_sol_map.count(curr_need)) {
                return {idx_sol_map[curr_need], i};
            }
            idx_sol_map[nums[i]] = i;
        }
        return {};
    }
};
