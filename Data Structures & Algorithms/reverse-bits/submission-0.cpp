class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t bit = (n >> i) & 1u;
            reversed |= bit << (31 - i);
        }
        return reversed;
    }
};