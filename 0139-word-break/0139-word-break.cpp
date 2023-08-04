class Solution {
public:
    unordered_map<string,bool> mp;
     
    bool solve(string &s, vector<string>& wordDict,int idx,vector<int> &dp){
        if(idx==s.size()){
            return true;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        string temp="";
        for(int i=idx ; i<s.size() ; i++){
            temp+=s[i];
            if(mp[temp]){
                if(solve(s,wordDict,i+1,dp)){
                    return dp[idx]=true;
                }
            }
        }
        return dp[idx]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto w : wordDict){
            mp[w]=true;
        }
        vector<int> dp(s.size()+1,-1);
        return solve(s,wordDict,0,dp);
    }
};