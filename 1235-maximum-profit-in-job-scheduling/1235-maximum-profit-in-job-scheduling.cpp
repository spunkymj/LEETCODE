class Solution {
public:
    int next(vector<vector<int>> &v , int idx){
        int l=idx+1;
        int r=v.size()-1;
        int j=r+1;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(v[idx][1]<=v[mid][0]){
                j=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return j;
    }

    int solve(vector<vector<int>> &v,int idx,int n,vector<int> &dp){
        if(idx==n){
            return 0;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        int j=next(v,idx);
        int c1=v[idx][2]+solve(v,j,n,dp);

        int c2=solve(v,idx+1,n,dp);

        return dp[idx]=max(c1,c2);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<int> dp(n,-1);
        vector<vector<int>> v(n, vector<int>(3));
        for(int i=0 ; i<n ; i++){
            v[i][0]=startTime[i];
            v[i][1]=endTime[i];
            v[i][2]=profit[i];
        }
        sort(v.begin(),v.end());
        return solve(v,0,n,dp);
    }
};