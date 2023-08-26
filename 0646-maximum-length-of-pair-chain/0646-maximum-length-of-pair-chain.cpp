class Solution {
public:
    bool static cmp(vector<int> &v1,vector<int> &v2){
        return v1[0]<v2[0];
    }

    int solve(vector<vector<int>>& pairs,int idx,vector<int> &dp){
        if(idx==pairs.size()){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }

        int not_pick=solve(pairs,idx+1,dp);
        int new_idx=upper_bound(pairs.begin(),pairs.end(),vector<int>(2,pairs[idx][1]+1))-pairs.begin();
        int pick=1+solve(pairs,new_idx,dp);
        return dp[idx]=max(pick,not_pick);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        vector<int> dp(pairs.size(),-1);
        return solve(pairs,0,dp);
    }
};