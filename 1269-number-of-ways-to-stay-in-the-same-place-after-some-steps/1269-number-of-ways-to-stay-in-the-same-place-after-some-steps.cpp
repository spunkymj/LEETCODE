class Solution {
public:

    int mod=1e9+7;
    int n;
    int solve(int steps, int arrLen,int idx, vector<vector<int>> &dp){
        if(idx>=arrLen || idx<0){
            return 0;
        }
        if(steps==0){
            return idx==0;
        }
        
        if(dp[idx][n+steps]!=-1){
            return dp[idx][n+steps];
        }
        
        int case1=solve(steps-1,arrLen,idx-1,dp)%mod;
        int case2=solve(steps-1,arrLen,idx+1,dp)%mod;
        int case3=solve(steps-1,arrLen,idx,dp)%mod;
        return dp[idx][n+steps]=((case1+case2)%mod+case3)%mod;
    }

    int numWays(int steps, int arrLen) {
        n=steps;
        vector<vector<int>> dp(n+1,vector<int>(2*n+1,-1));
        return solve(n,arrLen,0,dp);
    }
};