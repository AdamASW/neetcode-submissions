class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask;
        int ones = 0;
        for (int i = 31; i >= 0; i--) {
            mask = pow(2,i);
            if ((mask & n) == mask) ones += 1;
        }
        return ones;
    }
};
