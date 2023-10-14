class Solution {
public:
    int n;

    //Here curr_time gives the possible number of walls that can be painted by free painter
    int solve(vector<int>& cost, vector<int>& time,int idx,int curr_time,vector<vector<int>> &dp){
        if(curr_time>=(n-idx)){
            return 0;
        }
        if(idx==n){
            return 1e9;
        }

        if(dp[idx][n+curr_time]!=-1){
            return dp[idx][n+curr_time];
        }

        //to be done by free painter 
        int case1=solve(cost,time,idx+1,curr_time-1,dp);

        //to be done by paid painter
        int case2=cost[idx]+solve(cost,time,idx+1,curr_time+time[idx],dp);

        return dp[idx][n+curr_time]=min(case1,case2);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n=cost.size();
        vector<vector<int>> dp(n,vector<int>(2*n+1,-1));
        return solve(cost,time,0,0,dp);
    }
};