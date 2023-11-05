class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();
        map<int,long long> mp;
        long long ans=-1e18;
        for(int i=0 ; i<n ; i++){
            long long pos=nums[i]-i;
            long long sum=nums[i];
            auto it=mp.upper_bound(pos);
            if(it!=mp.begin()){
                sum=max(sum,sum+prev(it)->second);
            }
            mp[pos]=sum;
            ans=max(ans,sum);
            for( ; it!=mp.end() && it->second<=sum ;){
                mp.erase(it++);
            }
        }
        return ans;
    }
};