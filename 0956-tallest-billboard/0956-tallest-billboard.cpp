class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int sum=0;
        for(auto &e : rods){
            sum+=e;
        }
        unordered_map<int,int> dp;
        dp[0]=0;
        for(int i=0 ; i<n ; i++){
            unordered_map<int,int> new_dp=dp;
            for(auto &[x,y] : dp){
                    int longer=y;
                    int shorter=y-x;
                    int diff=x;
                new_dp[diff+rods[i]]=max(max(new_dp[diff+rods[i]],0),longer+rods[i]);
                   
                    
                    int newDiff=abs(shorter+rods[i]-longer);
             new_dp[newDiff]=max(max(new_dp[newDiff],0),max(shorter+rods[i],longer));
                    
            }
            dp=new_dp;
        }
        return dp[0];
    }
};