class Solution {
public:
    long long mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<long long> bit(32, 0); // count set bits
        long long res = 0, mod = 1e9 + 7;
        
        for (int i = 0; i < 31; i++) {
            for (int num : nums) {
                if (num & (1 << i)) {
                    bit[i]++;
                }
            }
        }
        
        for (int j = 1; j <= k; j++) {
            long long x = 0; // form the maximum number with the available bit counts
            for (int i = 0; i < 31; i++) {
                if (bit[i] > 0) {
                    x |= (1 << i);
                    bit[i]--;
                } 
            } 
            res += (x * x);
            res %= mod;
        }
        
        return res;
    }
};