class Solution {
public:
    const int mod=1e9+7;
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long,long long> mp;
        long long ans=0;
        for(auto e : nums){
            long long t=e;
            long long r=0;
            while(t){
                r=r*10LL+t%10LL;
                t/=10;
            }
            ans+=mp[e-r];
            ans%=mod;
            mp[e-r]++;
        }
        return ans;
    }
};