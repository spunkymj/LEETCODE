class Solution {
public:
    const int mod=1e9+7;

    int solve(int n,int prev,vector<vector<int>> &adj,vector<vector<int>> &dp){
        if(n==0){
            return 1;
        }
        if(dp[n][prev]!=-1){
            return dp[n][prev];
        }

        int curr=0;
        for(auto nbr : adj[prev]){
            curr+=solve(n-1,nbr,adj,dp);
            curr%=mod;
        }

        return dp[n][prev]=curr;
    }

    int knightDialer(int n) {
        vector<vector<int>> adj={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4},{0,1,2,3,4,5,6,7,8,9}};
        vector<vector<int>> dp(n+1,vector<int>(11,-1));
        return solve(n,10,adj,dp);
    }
};