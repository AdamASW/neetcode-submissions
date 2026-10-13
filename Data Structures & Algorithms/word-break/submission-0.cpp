class Solution {
public:
    unordered_map<string,bool> mp;

    bool wordBreak(string s, vector<string>& wordDict) {
        if (mp.count(s)) return mp[s];
        if (count(wordDict.begin(), wordDict.end(), s)) {
            mp[s] = true;
            return true;
        }
        int n = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (count(wordDict.begin(), wordDict.end(), s.substr(0,i+1))) {
                string smaller_word = s.substr(i+1, (n-1)-(i+1)+1);
                if (wordBreak(smaller_word, wordDict)) {
                    mp[s] = true;
                    return true;
                }
            }
        }
        mp[s] = false;
        return false;
    }
};