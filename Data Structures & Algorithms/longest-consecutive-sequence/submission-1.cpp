class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> seen;
        sort(nums.begin(), nums.end());
        int count = 0;
        int max_count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i])) { continue; }
            else { seen.insert(nums[i]); }
            if (i == 0) {
                count += 1;
                continue;
            }
            max_count = ((nums[i] - nums[i-1]) == 1) ? max({max_count, count+1}) : max_count;
            count = ((nums[i] - nums[i-1]) == 1) ? count + 1 : 1; 
        }
        return max_count;
    }
};
