class Solution {
public:
    int integerBreak(int n) {
        if(n==2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        long long ret=0;
        for(int k=2 ; k<=n; k++){
            long long ans=1;
            long long nn=n;
            while(nn-k>1){
                ans*=k;
                nn-=k;
            }
            ans*=nn;
            ret=max(ret,ans);
        }
        return ret;
    }
};