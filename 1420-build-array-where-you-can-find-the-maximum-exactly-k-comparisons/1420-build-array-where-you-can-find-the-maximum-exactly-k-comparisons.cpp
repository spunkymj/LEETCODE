class Solution {
public:
    long long mod=1e9+7;

    long long solve(int k,int m,int n,int idx,int last,vector<vector<vector<long long>>> &dp){
        if(idx==n){
            return k==0;
        }
        if(k<0){
            return 0; 
        }

        if(dp[k][idx][last]!=-1){
            return dp[k][idx][last];
        }
        long long val=0;
        for(int i=1 ; i<=m ; i++){
            if(i>last){
                val+=solve(k-1,m,n,idx+1,i,dp);
                val%=mod;
            }
            else{
                val+=solve(k,m,n,idx+1,last,dp);
                val%=mod;
            }
        }
        return dp[k][idx][last]=val%mod;
    }

    int numOfArrays(int n, int m, int k) {
        if(k>m || k>n || k==0){
            return 0;
        }
        long long ans=0;
        vector<vector<vector<long long>>> dp(k+1,vector<vector<long long>>(n+1,vector<long long>(m+1,-1))) ;
        return solve(k,m,n,0,0,dp)%mod;
    }
};