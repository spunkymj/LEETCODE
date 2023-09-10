#define ll long long

ll N=1002;
ll mod=1e9+7;

vector<ll> fac(N, 1);
vector<ll> invfac(N,1);

ll binpow(ll x, ll y)
{
    ll ans = 1;
    while (y > 0)
    {
        if (y % (ll)2 == 1)
        {
            ans *= x;
            ans %= mod;
        }
        x = (x * x) % mod;
        y /= (ll)2;
    }
    return ans;
}

ll ncr(ll n, ll r)
{
    ll nf = fac[n];
    ll rf = invfac[r];
    ll nmrf = invfac[n - r];
    ll ret = nf;
    ret *= rf;
    ret %= mod;
    ret *= nmrf;
    ret %= mod;
    return ret;
}

void processFact()
{
    for (ll i = 1; i < N; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    for (ll i = 0; i < N; i++)
        invfac[i] = binpow(fac[i], mod - 2);
}

class Solution {
public:
    int countOrders(int n) {
        processFact();
        ll ans=fac[2*n];
        ans*=binpow(invfac[2],n);
        return ans%mod;
    }
};