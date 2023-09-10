#define ll long long
class Solution {
public:
    int mod=1e9+7;

    ll calcpower(ll x, ll n)
    {
        if (n == 1)
        {
            return x;
        }
        ll temp = calcpower(x, n / 2);
        if (n & 1)
        {
            return ((((x * temp) % mod) * temp) % mod);
        }
        return (temp * temp) % mod;
    }

    // Fermat's Little Theorem : a^p=a mod(p)  =>   a^(p-2)=(a^-1)mod(p)
    ll modinv(ll num)
    {
        return calcpower(num, mod - 2);
    }


    vector<int> calculateZ(string &s){
        vector<int> z(s.size(),0);
        int l=0;
        int r=0;
        for(int k=1 ; k<s.size() ; k++){
            if(k>r){
                l=r=k;
                while(r<s.size() && s[r]==s[r-l]){
                    r++;
                }
                z[k]=r-l;
                r--;
            }
            else{
                int k1=k-l;
                if(z[k1]<r-k+1){
                    z[k]=z[k1];
                }
                else{
                    l=k;
                    while(r<s.size() && s[r]==s[r-l]){
                        r++;
                    }
                    z[k]=r-l;
                    r--;
                }
            }
        }
        return z;
    }

    int numberOfWays(string s, string t, long long k) {
        if(s.size()!=t.size()){
            return 0;
        }
        string temp=t;
        temp+='$';
        temp+=s;
        temp+=s;

        vector<int> z=calculateZ(temp);
        vector<long long> v;
        int n=s.size();
        if(k%2==0){
            v.resize(n,(((calcpower(n-1,k)-1)*modinv(n))%mod));
            v[0]+=1;
            v[0]%=mod;
        }
        else{
            v.resize(n,(((calcpower(n-1,k)+1)*modinv(n))%mod));
            v[0]-=1;
            v[0]+=mod;
            v[0]%=mod;
        }

        int ans=0;
        for(int i=0 ; i<z.size() ; i++){
            if(z[i]==t.size()){
                if(i-t.size()-1>=0 && i-t.size()-1<n){
                    ans+=v[i-t.size()-1];
                }
                ans%=mod;
            }
        }

        return ans%mod;
    }
};