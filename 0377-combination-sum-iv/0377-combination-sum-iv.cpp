class Solution {
public:
    long long solve(int idx,vector<int>& nums, int target,vector<vector<long long>> &dp){
        if(target==0){
            return 1;
        }
        if(idx==nums.size()){
            return 0;
        }

        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }

        long long comb=0;
        for(int i=idx ; i<nums.size() ; i++){
            if(nums[i]<=target){
                comb+=solve(0,nums,target-nums[i],dp);
            }
        }
        return dp[idx][target]=comb;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};