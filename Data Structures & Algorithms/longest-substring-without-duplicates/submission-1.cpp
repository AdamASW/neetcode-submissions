class Solution {
public:

    // unordered_map<string, int> mp;

    int lengthOfLongestSubstring(string s) {
        // int s_length = s.size();
        // set<char> curr_set;
        // if (mp.count(s)) {
        //     return mp[s];
        // } else {
        //     for (char c : s) {
        //         curr_set.insert(c);
        //     }
        //     if (curr_set.size() == s_length) {
        //         mp.insert({s, s_length});
        //         return s_length;
        //     } else {
        //         string s_left = s.substr(1);
        //         string s_right = s.substr(0, s.size() - 1);
        //         int answer_left = lengthOfLongestSubstring(s_left);
        //         int answer_right = lengthOfLongestSubstring(s_right);
        //         int answer = max(answer_left, answer_right);
        //         mp[s] = answer;
        //         return answer;
        //     }
        // }

        unordered_set<char> chars;
        int l = 0, longest = 0;

        for (int r = 0; r < s.size(); r++) {
            while (chars.count(s[r])) {
                // If the right char is in duplicate, move the left until it is valid again.
                chars.erase(s[l]);
                l++;
            }
            // Add right char to hash set since it's been discovered.
            chars.insert(s[r]);
            // For the current valid substring, check if longer than existing longest.
            longest = max(longest, r - l + 1);
        }
        // Return the value.
        return longest;
    }
};