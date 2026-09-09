class Solution {
public:
    int characterReplacement(string s, int k) {
        // Variant of the dynamic sliding window problem with a tolerance:
        unordered_map<char, int> frequency;

        int l = 0;
        int longest = 0;
        int max_frequency = 0;

        for (int r = 0; r < s.size(); r++) {
            frequency[s[r]]++;
            // We need max_frequency to compute how many characters must be replaced.
            // and compare that value with k.
            max_frequency = max(frequency[s[r]], max_frequency);

            while(((r - l + 1) - max_frequency) > k) {
                // While the string violates the condition, move the left idx.
                // Addiitonally, remove the old character from scope.
                frequency[s[l]]--;
                l++;
            }
            longest = max(longest, (r - l + 1));
        }
        return longest;
    }
};
