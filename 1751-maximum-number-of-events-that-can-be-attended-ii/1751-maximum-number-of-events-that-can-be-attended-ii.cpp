class Solution {
public:
    int upper_bound(vector<vector<int>> &events,int st){
        if(events[events.size()-1][0]<=st){
            return events.size();
        }
        int l=0;
        int r=events.size()-1;
        int ret=-1;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(st<events[mid][0]){
                ret=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ret;
    }
    
    int solve(vector<vector<int>>& events, int k,int start_idx,int new_start,vector<vector<int>> &dp){
        if(k==0){
            return 0;
        }
        if(start_idx==events.size()){
            return 0;
        }
        if(dp[start_idx][k]!=-1){
            return dp[start_idx][k];
        }
        auto it=upper_bound(events,new_start);
        
        int ans=0;
        for(int i=max(start_idx,it) ; i<events.size() ; i++){
            ans=max(ans,events[i][2]+solve(events,k-1,i+1,events[i][1],dp));
        }
        return dp[start_idx][k]=ans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        return solve(events,k,0,0,dp);
    }
};