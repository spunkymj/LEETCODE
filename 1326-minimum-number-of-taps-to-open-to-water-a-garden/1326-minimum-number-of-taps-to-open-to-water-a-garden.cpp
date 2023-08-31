class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=0  ; i<n+1 ; i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            for(int pos=start ; pos<=end ; pos++){
                dp[end]=min(dp[end],dp[pos]+1);
            }
        }
        return dp[n]==1e9 ? -1 : dp[n];
    }
};