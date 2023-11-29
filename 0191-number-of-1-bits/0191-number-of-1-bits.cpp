#define countbits(x) __builtin_popcount(x)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return countbits(n);
    }
};