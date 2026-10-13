class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // (i) -> (nums[i]) ->
        int current_idx = 0;
        int fast_idx = 0;
        for (int i = 0; i <= nums.size(); i++) {
            current_idx = nums[current_idx];
            fast_idx = nums[nums[fast_idx]];
            if (current_idx == fast_idx) {
                int slow_idx = 0;
                while (slow_idx != current_idx) {
                    current_idx = nums[current_idx];
                    slow_idx = nums[slow_idx];
                }
                return current_idx;
            }
        }
    }
};
