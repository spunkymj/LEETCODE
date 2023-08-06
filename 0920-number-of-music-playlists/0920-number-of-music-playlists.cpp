class Solution {
public:
    int mod=1e9+7;

    long long solve(int goal,int songs,int &n,int &k,vector<vector<long long>> &dp){
        if(goal==0 && songs==0){
            return 1;
        }
        if(goal==0 || songs==0){
            return 0;
        }
        if(dp[goal][songs]!=-1){
            return dp[goal][songs];
        }

        long long ans=0;
        ans=(solve(goal-1,songs-1,n,k,dp)*(long long)(n-songs+1))%mod;
        if(songs>k){
            ans+=(solve(goal-1,songs,n,k,dp)*(long long)(songs-k))%mod;
            ans%=mod;
        }

        return dp[goal][songs]=ans;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(goal+1,vector<long long>(n+1,-1));
        return solve(goal,n,n,k,dp)%mod;
    }
};