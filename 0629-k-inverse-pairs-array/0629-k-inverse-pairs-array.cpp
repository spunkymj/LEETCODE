#include <vector>

class Solution {
public:
    // Function to calculate the number of arrays with exactly k inverse pairs.
    int kInversePairs(int n, int k) {
        // 2D vector to store dynamic programming results.
        // dp[i][j] represents the number of arrays of length i with j inverse pairs.
        // Initialize with zeros.
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));

        // Iterate over the length of the array.
        for (int i = 1; i <= n; i++) {
            // Iterate over the number of inverse pairs.
            for (int j = 0; j <= k; j++) {
                // Base case: If j is 0, there is only one way to arrange the array.
                if (j == 0) {
                    dp[i][j] = 1;
                } else {
                    // Iterate over possible values of p to calculate dp[i][j].
                    for (int p = 0; p <= min(i - 1, j); p++) {
                        // Update dp[i][j] using the recurrence relation.
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % 1000000007;
                    }
                }
            }
        }

        // The final result is stored in dp[n][k].
        return dp[n][k];
    }
};