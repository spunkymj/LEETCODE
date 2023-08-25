class Solution {
public:
    long long mod=1e9+7;
    long long dp[11][2][2][102];

    long long solve(string &s,int prev,bool tight=1,int pos=0,bool zero=1){
        if(pos==s.size()){
            return (!zero) ;
        }

        if(dp[prev+1][tight][zero][pos]!=-1){
            return dp[prev+1][tight][zero][pos];
        }

        int start=0;
        int end=(tight ? s[pos]-'0' : 9);
        int ans=(zero ? solve(s,0,0,pos+1,zero) : 0);

        for(int i=start ; i<=end ; i++){
            int newtight=(tight && (i==s[pos]-'0'));
            if(zero && i!=0){
                ans+=solve(s,i,newtight,pos+1,false)%mod;
                ans%=mod;
            }
            else if(!zero && abs(i-prev)==1){
                ans+=solve(s,i,newtight,pos+1,false)%mod;
                ans%=mod;
            }
        } 
        
        return dp[prev+1][tight][zero][pos]=ans%mod;
    }

    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        long long mini=solve(low,-1);
        memset(dp,-1,sizeof(dp));
        long long maxi=solve(high,-1);
        bool add=true;
        for(int i=1 ; i<low.size() ; i++){
            if(abs((low[i]-'0')-(low[i-1]-'0'))!=1){
                add=false;
                break;
            }
        }
        
        return ((maxi-mini+1000000007)+add)%mod;
    }
};