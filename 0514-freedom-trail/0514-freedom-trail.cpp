class Solution {
public:

    int help(int idx,int shift,string &ring,string &key,vector<vector<int>> &dp){
        if(idx==key.size()){
            return 0;
        }

        if(dp[idx][shift]!=-1){
            return dp[idx][shift];
        }

        int curr=1e9;
        for(int i=0 ; i<ring.size() ; i++){
            if(ring[i]==key[idx]){
                int add1=abs(i-shift);
                int add2=((ring.size()-add1));
                curr=min(curr,add1+help(idx+1,i,ring,key,dp));
                curr=min(curr,add2+help(idx+1,i,ring,key,dp));
            }   
        }

        return dp[idx][shift]=curr;
    }

    int findRotateSteps(string ring, string key) {
        int n=key.size();
        int m=ring.size();
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        return help(0,0,ring,key,dp)+(int)key.size();
    }
};