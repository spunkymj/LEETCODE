class Solution {
public:
    bool helper(int idx,string &s,int curr,vector<vector<int>> &dp){
        if(curr<0){
            return false;
        }
        if(idx==s.size()){
            return (curr==0);
        }

        if(dp[idx][curr]!=-1){
            return dp[idx][curr];
        }
        bool chk=false;
        if(s[idx]=='('){
            chk|=(helper(idx+1,s,curr+1,dp));
        }
        else if(s[idx]==')'){
            chk|=(helper(idx+1,s,curr-1,dp));
        }
        else{
            chk|=(helper(idx+1,s,curr+1,dp));
            chk|=(helper(idx+1,s,curr-1,dp));
            chk|=(helper(idx+1,s,curr,dp));
        }

        return dp[idx][curr]=chk;
    }   

    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return helper(0,s,0,dp);
    }
};