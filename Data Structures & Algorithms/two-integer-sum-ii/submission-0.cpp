class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < numbers.size(); i++) {
            int n = numbers[i];
            int need = target - n;
            if (mp.count(need)) {
                vector<int> solution = {((mp[need]) + 1), (i + 1)};
                return solution;
            } else {
                mp.insert({n, i});
            }
        }
    }
};