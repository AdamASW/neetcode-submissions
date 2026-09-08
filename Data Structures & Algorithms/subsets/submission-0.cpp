class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        // Recursively remove each of the elements and add to set.
        if (nums.empty()) { return {{}}; }
        int first_element = nums[0];
        vector<int> nums_without_first = nums;
        nums_without_first.erase(nums_without_first.begin());
        vector<vector<int>> subsets_without_first = subsets(nums_without_first);
        vector<vector<int>> subsets_with_first = {};
        for (auto subset : subsets_without_first) {
            subset.push_back(first_element);
            subsets_with_first.push_back(subset);
        }
        subsets_without_first.reserve(subsets_without_first.size() + subsets_with_first.size()); // Reserve.
        subsets_without_first.insert(subsets_without_first.end(), subsets_with_first.begin(), subsets_with_first.end());
        return subsets_without_first;
    }
};

