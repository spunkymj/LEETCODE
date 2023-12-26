class Solution {
public:
    const int mod=1e9+7;
    long long solve(long long t,int n,int k,vector<vector<long long>> &dp){
        if(n==0){
            return t==0;
        }

        if(dp[t][n]!=-1){
            return dp[t][n];
        }

        int curr=0;
        for(long long i=1 ; i<=k ; i++){
            if(i<=t){
                curr+=solve(t-i,n-1,k,dp);
                curr%=mod;
            }
        }

        return dp[t][n]=curr;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(target+1,vector<long long> (n+1,-1));
        return solve(target,n,k,dp)%mod;
    }
};