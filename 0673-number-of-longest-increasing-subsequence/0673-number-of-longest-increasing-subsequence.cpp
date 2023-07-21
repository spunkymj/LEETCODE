class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int ans=0;
        int maxi=0;
        for(int idx=0 ; idx<n ; idx++){
            for(int prev=0 ; prev<idx; prev++){
                if(nums[prev]<nums[idx] && 1+dp[prev]>dp[idx]){
                    dp[idx]=1+dp[prev];
                    cnt[idx]=cnt[prev];
                }
                else if(nums[prev]<nums[idx] && (1+dp[prev])==dp[idx]){
                    cnt[idx]+=cnt[prev];
                }
            }
            maxi=max(maxi,dp[idx]);
        }
        for(int i=0 ; i<n ; i++){
            if(dp[i]==maxi){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};