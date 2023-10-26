class Solution {
public:
    int mod=1e9+7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        map<long long,long long> mp;
        for(auto e : arr){
            mp[e]=1;
        }
        long long ans=0;
        for(auto &m : mp){
            ans+=m.second;
            ans%=mod;
            long long num=m.first;
            long long tot=m.second;
            for(auto &mm : mp){
                int f=mm.first;
                if(f>num){
                    break;
                }
                if(num%f==0){
                    if(mp[num/f]){
                        long long val=mp[f]*mp[num/f];
                        tot+=val;
                        tot%=mod;
                        ans+=val;
                        ans%=mod;
                    }
                }
            }
            mp[num]=tot;
        }
        return  ans;
    }
};