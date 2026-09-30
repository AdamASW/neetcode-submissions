class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if (n > s2.size()) { return false;}
        unordered_map<char, int> char_set = {};
        for (char c : s1) {
            char_set[c]++;
        }
        int r = 0;
        unordered_map<char, int> curr_set = {};
        for (int l = 0; l <= (s2.size() - n); l++) {
            while (r - l < n) {
                curr_set[s2[r]]++;
                r += 1;
            }
            if (curr_set == char_set) {
                return true;
            }
            char del_char = s2[l];
            curr_set[del_char]--;
            if (curr_set[del_char] == 0) {
                curr_set.erase(del_char);
            }
        }
        return false;
    }
};