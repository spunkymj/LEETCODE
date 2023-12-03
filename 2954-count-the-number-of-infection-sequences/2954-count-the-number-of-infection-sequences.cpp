long long N=1e5;

long long fac[100001] = {}, invfac[100001] = {}, mod = 1000000007;

class Solution {
public:
    
long long binpow(long long x, long long y)
{
    long long ans = 1;
    while (y > 0)
    {
        if (y % (long long)2 == 1)
        {
            ans *= x;
            ans %= mod;
        }
        x = (x * x) % mod;
        y /= (long long)2;
    }
    return ans;
}

long long ncr(long long n, long long r)
{
    long long nf = fac[n];
    long long rf = invfac[r];
    long long nmrf = invfac[n - r];
    long long ret = nf;
    ret *= rf;
    ret %= mod;
    ret *= nmrf;
    ret %= mod;
    return ret;
}

void processFact()
{
    if(fac[1]==1){
        return;
    }
    fac[0]=invfac[0]=1;
    for (long long i = 1; i <= N; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    for (long long i = 0; i <= N; i++)
        invfac[i] = binpow(fac[i], mod - 2LL);
}


    int numberOfSequence(int n, vector<int>& sick) {
        processFact();
        long long ans=fac[n-(int)sick.size()];
        for(int i=1 ; i<sick.size() ; i++){
            long long grp=sick[i]-sick[i-1]-1;
            if(grp>0){
                ans*=binpow(2LL,grp-1LL);
                ans%=mod;
                ans*=invfac[grp];
                ans%=mod;
            }
        }
        ans*=invfac[(sick[0]-0)];
        ans%=mod;
        ans*=invfac[(n-1-sick[sick.size()-1])];
        ans%=mod;
        return ans;
    }
};