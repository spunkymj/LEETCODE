class Solution {
public:
    bool solve(string &s1,string &s2,int i,int j,string &s3,vector<vector<int>> &dp){
        if(i+j==s3.size()){
            return true;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool ans=false;
        if(i<s1.size() && s3[i+j]==s1[i]){
            ans|=solve(s1,s2,i+1,j,s3,dp);
        }
        if(j<s2.size() && s3[i+j]==s2[j]){
            ans|=solve(s1,s2,i,j+1,s3,dp);
        }
        return dp[i][j]=ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,0,0,s3,dp);
    }
};