class Solution {
public:
    bool solve(int idx,int prev,vector<int>& stones,vector<vector<int>> &dp){
        if(idx==stones.size()-1){
            return true;
        }

        if(dp[idx][prev]!=-1){
            return dp[idx][prev];
        }

        bool ans=false;
        int diff=stones[idx]-stones[prev];
        int new_idx=-1;
        if(diff-1>0){
            new_idx=lower_bound(stones.begin(),stones.end(),stones[idx]+diff-1)-stones.begin();
            if(new_idx<stones.size() && stones[new_idx]==stones[idx]+diff-1){
                ans|=solve(new_idx,idx,stones,dp);
            }
        }
        if(diff>0){
            new_idx=lower_bound(stones.begin(),stones.end(),stones[idx]+diff)-stones.begin();
            if(new_idx<stones.size() && stones[new_idx]==stones[idx]+diff){
                ans|=solve(new_idx,idx,stones,dp);
            }
        }
        new_idx=lower_bound(stones.begin(),stones.end(),stones[idx]+diff+1)-stones.begin();
        if(new_idx<stones.size() && stones[new_idx]==stones[idx]+diff+1){
            ans|=solve(new_idx,idx,stones,dp);
        }

        return dp[idx][prev]=ans;
    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,stones,dp);
    }
};