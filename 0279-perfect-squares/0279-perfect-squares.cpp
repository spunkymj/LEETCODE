class Solution {
public:
    int solve(int n)
    {
        vector<int>dp(n + 1, INT_MAX);
        dp[0] = 0; 
        for (int target = 1; target <= n; target++)
        {
            int count = INT_MAX;
            for (int num = 1; num <= sqrt(target); num++)
            {
                int sqNum = num * num;
                int currCount = 1 + dp[target - sqNum];
                count = min(count, currCount);
            }
            dp[target] = count;
        }
        return dp[n];
    } 
    int numSquares(int n) 
    {
        return solve(n);
    }
};