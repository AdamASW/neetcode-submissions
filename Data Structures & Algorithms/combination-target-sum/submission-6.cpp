class Solution {
public:

    void backtrack(vector<int>& nums, vector<int>& acc, int target, int sum, int n,
        vector<vector<int>>& answer) {
        // Base cases:
        if (sum == target) {
            answer.push_back(acc);
            return;
        }
        else if ((sum > target) || (n >= nums.size())) {
            return;
        }
        // Choices:
            // include element and remove from consideration.
            // include element but consider again.
            // exclude element (move on).
        acc.push_back(nums[n]);
        int sum_include = sum + nums[n];

        // backtrack(nums, acc_include, target, sum_include, n+1, answer);
        backtrack(nums, acc, target, sum_include, n, answer); //choose and stay.
        acc.pop_back();
        backtrack(nums, acc, target, sum, n+1, answer); //skip
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        vector<int> acc;
        backtrack(nums, acc, target, 0, 0, answer);
        return answer;
    }
};
