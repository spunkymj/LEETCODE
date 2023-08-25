class Solution {
public:
    int k;
    int dp[2][10][10][10][20][2];
    int solve(string &s,int tight=1,int pos=0,int odd=0,int even=0,int rem=0,bool zero=true){
        if(pos==s.size()){
            return ((!zero) && (rem==0) && (odd==even)) ;
        }

        if(dp[tight][pos][odd][even][rem][zero]!=-1){
            return dp[tight][pos][odd][even][rem][zero];
        }

        int start=0;
        int end=(tight ? s[pos]-'0' : 9);
        int ans=(zero ? solve(s,0,pos+1,odd,even,rem,zero) : 0);

        for(int i=start ; i<=end ; i++){
            int newtight=(tight && (i==s[pos]-'0'));
            int newodd=odd+(i&1);
            int neweven=even+((!zero || i > 0) && i % 2 == 0);

            if(zero && i!=0){
                ans+=solve(s,newtight,pos+1,newodd,neweven,i%k,false);
            }
            else if(!zero){
                ans+=solve(s,newtight,pos+1,newodd,neweven,(rem*10+i)%k,false);
            }
        } 
        
        return dp[tight][pos][odd][even][rem][zero]=ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        this->k=k;
        string lo=to_string(low-1);
        string hi=to_string(high);
        memset(dp,-1,sizeof(dp));
        int maxi=solve(hi);
        memset(dp,-1,sizeof(dp));
        int mini=solve(lo);
        return maxi-mini;
    }
};