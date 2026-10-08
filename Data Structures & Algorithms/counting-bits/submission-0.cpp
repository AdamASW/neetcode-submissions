class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer;
        unordered_map<uint32_t,int> mp;
        if (n == 0) return {0};
        if (n == 1) return {0,1};
        answer.push_back(0);
        answer.push_back(1);
        mp[0u] = 0;
        mp[1u] = 1;
        int two_pow = 1; // Tracks the length of the bit representation.
        uint32_t left_mask; //mask to get if MSB is 1 or 0.
        uint32_t right_mask; //mask to get the n-1 least significant bits (which are already in mp).
        for (uint32_t num = 2; num <= n; num++) {
            if (num >= pow(2,two_pow)) two_pow += 1;
            left_mask = 1u << two_pow-1;
            right_mask = left_mask - 1;
            mp[num] = 1 + mp[(right_mask & num)];
            answer.push_back(mp[num]);
        }
        return answer;
    }
};
