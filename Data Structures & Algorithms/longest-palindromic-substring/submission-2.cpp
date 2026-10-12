class Solution {
public:
    string palindrome(string s, int idx) {
        int n = s.size();
        int l = idx, r = idx;

        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }

        string odd = s.substr(l + 1, r - l - 1);

        l = idx - 1;
        r = idx;

        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }

        string even = s.substr(l + 1, r - l - 1);

        return (odd.size() >= even.size()) ? odd : even;
    }

    string longestPalindrome(string s) {
        // dp[i] = longest palindromic substring with a center up to i.
        unordered_map<int,string> mp;
        int n = s.size();
        if (n == 1) return s;
        mp[0] = s[0];
        for (int i = 1; i < n; i++) {
            string curr_s = palindrome(s,i);
            mp[i] = (mp[i-1].size() < curr_s.size()) ? curr_s : mp[i-1];
        }
        return mp[n-1];
    }
};
