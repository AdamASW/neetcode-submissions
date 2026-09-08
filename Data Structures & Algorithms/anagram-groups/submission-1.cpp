class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) {
            return vector<vector<string>> {strs};
        }
        int sum_empties = 0;
        unordered_map<string, vector<string>> mp;
        for (string str_elem : strs) {
            if (str_elem == "") {
                sum_empties += 1;
                continue;
            }
            string curr_key = str_elem;
            sort(curr_key.begin(), curr_key.end()); // Started with set<char> as key but didn't want to define hash.
            if (mp.count(curr_key)) {
                mp[curr_key].push_back(str_elem);
            } else {
                vector<string> new_entry_vector = {str_elem};
                mp[curr_key] = new_entry_vector;
            }
        }
        vector<vector<string>> group_anagrams;
        for (const auto& [anagram, anagram_vector] : mp) {
            group_anagrams.push_back(anagram_vector);
        }
        if (sum_empties > 0) {
            vector<string> empty_string_vector;
            for (int i = 0; i < sum_empties; i++) {
                empty_string_vector.push_back("");
            }
            group_anagrams.push_back(empty_string_vector);
        }
        return group_anagrams;
    }
};
