class Solution {
public:
    int solve(vector<int>& arr, int k,int l,vector<int> &dp){
        if(l==arr.size()){
            return 0;
        }
        if(dp[l]!=-1){
            return dp[l];
        }
        int maxi=0;
        int ans=0;
        for(int i=l ; i<min(l+k,(int)arr.size()) ; i++){
            maxi=max(maxi,arr[i]);
            int val=(i-l+1)*maxi+solve(arr,k,i+1,dp);
            ans=max(ans,val);
        }
        return dp[l]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return solve(arr,k,0,dp);
    }
};