class Solution {
public:
    long long mod=1e9+7;

    long long val(long long n){
        return (n*(n+1LL))/(2LL);
    }

    int countHomogenous(string s) {
        vector<long long> c;
        int n=s.size();
        for(int i=0 ; i<n ; i++){
            int j=i;
            while(s[i]==s[j]){
                i++;
            }
            i--;
            c.push_back(i-j+1);
        }

        long long ans=0;
        for(int i=0 ; i<c.size() ; i++){
            ans+=val(c[i]);
            ans%=mod;
        }

        return ans;
    }
};