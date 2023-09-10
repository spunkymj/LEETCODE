class Solution {
public:
    int mod=1e9+7;
    int countOrders(int n) {
        long long ans=1;
        for(long long i=1 ; i<=n  ; i++){
            ans*=(2*i-1)*(2*i)/2;
            ans%=mod;
        }
        return ans;
    }
};