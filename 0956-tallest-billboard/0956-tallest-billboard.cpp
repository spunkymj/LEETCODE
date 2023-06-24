class Solution {
public:
    void solve(vector<int>& rods,vector<int> &dp,int l,int r,int sum){
        for(int i=l ; i<=r ; i++){
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
    }

    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int leftsum=0;
        int rightsum=0;
        int mid=n/2;
        for(int i=0 ; i<=mid ; i++){
            leftsum+=rods[i];
        }
        
        for(int i=mid+1; i<n ; i++){
            rightsum+=rods[i];
        }
        vector<int> dp1(leftsum+2,-1);
        dp1[0]=0;
        vector<int> dp2(rightsum+2,-1);
        dp2[0]=0;

        solve(rods,dp1,0,mid,leftsum);
        solve(rods,dp2,mid+1,n-1,rightsum);
        int ans=0;
        for(int i=0 ; i<=min(leftsum,rightsum) ; i++){
            if(dp1[i]!=-1 && dp2[i]!=-1){
                ans=max(ans,dp1[i]+(dp2[i]-i));
            }
        }
        return ans;
    }
};