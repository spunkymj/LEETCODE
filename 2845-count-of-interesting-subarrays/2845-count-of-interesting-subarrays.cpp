class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {        
        unordered_map<long long,long long> mp;
        long long ans = 0;
        int prefix = 0;
        int n = nums.size();
        mp[0]++;
        // We will take Prefix Sum of nums[i]%mod=k
        // For Example [3,1,9,6] [1,0,1,1] 
        // prefix = [1,1,2,2] if its count==k till index i

        for(int i=0;i<n;i++) {
            // if my current element%m=k
            if(nums[i]%mod==k){
                prefix++;
            }
            prefix%=mod;
            ans+=mp[(prefix-k+mod)%mod];
            mp[prefix]++;
        }
        return ans;
    }
};

