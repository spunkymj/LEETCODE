class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> dp(t+1,0);
        dp[0]=1;
        for(int target=0 ; target<=t ; target++){
            for(int idx=0 ; idx<n && nums[idx]<=target ; idx++){
                dp[target]+=dp[target-nums[idx]];
                if(dp[target]>INT_MAX){
                    dp[target]=INT_MAX;
                }
            }
        }
        return dp[t];
    }
};