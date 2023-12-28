class Solution {
public:
    int N;

    int val(int x){
        return (x==1 ? 0 : (x<10 ? 1 : (x<100 ? 2 : 3))); 
    }

    int solve(string &s,int idx,int k,vector<vector<int>> &dp){
        if(k<0){
            return N;
        }
        if(idx==N || (N-idx<=k)){
            return 0;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        int curr=N;
        int maxi=0;
        vector<int> freq(26,0);
        for(int i=idx ; i<N ; i++){
            maxi=max(maxi,++freq[s[i]-'a']);
            curr=min(curr,1+val(maxi)+solve(s,i+1,k-((i-idx+1)-maxi),dp));
        }
        return dp[idx][k]=curr;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        int n=s.size();
        N=n;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,k,dp);
    }
};