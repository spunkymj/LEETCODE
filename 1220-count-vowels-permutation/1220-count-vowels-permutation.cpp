class Solution {
public:
    long long mod=1e9+7;
    vector<vector<int>> adj={{1},{0,2},{0,1,3,4},{2,4},{0}};
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n+1,vector<long long>(5,0));
        for(int i=0 ; i<5 ; i++){
            dp[1][i]=1;
        }
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<5 ; j++){
                for(auto nbr : adj[j]){
                    dp[i+1][j]+=dp[i][nbr];
                    dp[i+1][j]%=mod;
                }
            }
        }
        long long ans=0;
        for(auto e : dp[n]){
            ans+=e;
            ans%=mod;
        }
        return ans;
    }
};