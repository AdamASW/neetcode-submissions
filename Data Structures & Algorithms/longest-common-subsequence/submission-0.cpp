class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j] = longest common subsequence of text1[0:i] and text2[0:j]
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        if (text1.size() == 1 && text2.size() == 1) {
            return (text1[0] == text2[0]) ? 1 : 0;
        }
        dp[0][0] = 0;
        // 1 indexed!
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                dp[i][j] = max({1 + dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                if (text1[i-1] == text2[j-1]) { 
                    dp[i][j] = max({1 + dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                } else {
                    dp[i][j] = max({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                }
            }
        }
    
        return dp[text1.size()][text2.size()];
    }
};
