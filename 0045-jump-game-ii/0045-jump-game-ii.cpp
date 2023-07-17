class Solution {
public:
    int solve(vector<int> &nums,int idx,vector<int> &dp){
        if(idx>=nums.size()-1){
            return 0;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        int ans=1e9;
        for(int i=1 ; i<=min(nums[idx],(int)nums.size()-1) ; i++){
            ans=min(ans,1+solve(nums,idx+i,dp));
        }
        return dp[idx]=ans;
    }

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};