class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1),bt(n,1);
        int maxi=0;
        int maxidx=-1;
        for(int idx=0 ; idx<n ; idx++){
            bt[idx]=idx;
            for(int prev=0 ; prev<idx; prev++){
                if(nums[idx]%nums[prev]==0 && 1+dp[prev]>dp[idx]){
                    dp[idx]=1+dp[prev];
                    bt[idx]=prev;
                }
            }
            if(dp[idx]>maxi){
                maxi=dp[idx];
                maxidx=idx;
            }
        }
        vector<int> ans;
        ans.push_back(nums[maxidx]);
        while(maxidx!=bt[maxidx]){
            ans.push_back(nums[bt[maxidx]]);
            maxidx=bt[maxidx];
        }
        return ans;
    }
};