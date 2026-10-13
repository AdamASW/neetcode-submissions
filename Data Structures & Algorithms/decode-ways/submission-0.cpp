class Solution {
public:
    int numDecodings(string s) {
        // include:exclude means do we count a digit as length 1 or 2.
        // dp[i] = {x,y} x and y represent the valid ways to decode s[0:i] where the grouping ends in a 1 or 2 digit number, respectively.
        
        unordered_map<int,pair<int,int>> mp;
        int n = s.size();
        char c = s[0];
        if (c != '0') { 
            mp[0] = {1,0};
        }
        else {
            return 0;
        }
        for (int i = 1; i < s.size(); i++) {
            int y1_count = 0, y2_count = 0;
            int prev_dig = s[i-1] - '0';
            int curr_dig = s[i] - '0';
            if (curr_dig == 0) {
                y1_count = 0;
                y2_count = (prev_dig == 1 || prev_dig == 2) ? mp[i-1].first : 0;
            } else {
                y1_count = mp[i-1].first + mp[i-1].second;
                y2_count = (prev_dig == 1 || (prev_dig == 2 && curr_dig <= 6)) ? mp[i-1].first : 0;
            }
            mp[i] = {y1_count, y2_count};
        }
        auto [x, y] = mp[n-1];
        int final_count = x + y;
        return final_count;
    }
};