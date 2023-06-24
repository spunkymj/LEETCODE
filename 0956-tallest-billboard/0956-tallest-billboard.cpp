class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int sum=0;
        for(auto &e : rods){
            sum+=e;
        }
        vector<int> dp(sum+1,-1);
        dp[0]=0;

        for(int i=0 ; i<n ; i++){
            vector<int> new_dp=dp;
            for(int j=0 ; j<=sum-rods[i] ; j++){
                if(dp[j]<0){
                    continue;
                }
                int longer=dp[j];
                int shorter=dp[j]-j;

                new_dp[j+rods[i]]=max(new_dp[j+rods[i]],longer+rods[i]);

                int newdiff=abs(shorter+rods[i]-longer);
                new_dp[newdiff]=max(new_dp[newdiff],max(longer,shorter+rods[i]));
                    
            }
            dp=new_dp;
        }
        return dp[0];
    }
};