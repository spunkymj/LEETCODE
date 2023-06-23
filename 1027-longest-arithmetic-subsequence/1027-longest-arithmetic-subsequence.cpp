class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(1001,1));
        int res=2;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int diff=nums[j]-nums[i];
                dp[j][500+diff]=max(dp[j][500+diff],1+dp[i][500+diff]);
                res=max(res,dp[j][500+diff]);
            }
        }
        return res;
    }
};