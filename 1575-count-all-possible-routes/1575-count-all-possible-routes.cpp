class Solution {
public:
    int mod=1e9+7;
    
    int solve(vector<int>& locations, int start, int finish, int fuel,vector<vector<int>> &dp){
        if(dp[start][fuel]!=-1){
            return dp[start][fuel];
        }
        
        int ans=0;
        if(start==finish){
            ans++;
        }
        
        for(int i=0 ; i<locations.size() ; i++){
            if(i==start){
                continue;
            }
            int reduce=abs(locations[i]-locations[start]);
            if(reduce<=fuel){
                ans+=solve(locations,i,finish,fuel-reduce,dp);
                ans=ans%mod;
            }
        }

        return dp[start][fuel]=ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(),vector<int>(fuel+1,-1));
        return solve(locations,start,finish,fuel,dp);
    }
};