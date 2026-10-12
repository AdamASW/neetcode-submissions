class Solution {
public:

    int palindromes(string s, int idx) {
        int n = s.size();
        int l = idx, r = idx;
        int count = 0;

        while ((l >= 0) && (r < n) && (s[l] == s[r])) {
            count++;
            l--;
            r++;
        }

        // string odd = s.sustr(l+1, r-l-1);

        l = idx - 1;
        r = idx;

        while ((l >= 0) && (r < n) && (s[l] == s[r])) {
            count++;
            l--;
            r++;
        }

        // string even = s.substr(l+1,r-l-1);
        // The only way that even and odd can be different is if they're made of the same chars.

        return count;
    }

    int countSubstrings(string s) {
        unordered_map<int,int> mp;
        int n = s.size();
        mp[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            mp[i] = mp[i-1] + palindromes(s,i);
        }
        return mp[n-1];
    }
};
