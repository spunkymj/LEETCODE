class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=1;

        vector<long long> prefix(n+1,0);
        prefix[0]=nums[0];
        for(int i=0 ; i<n ; i++){
            prefix[i+1]+=prefix[i]+nums[i];
        }
        for(long long i=1 ; i<n ; i++){
            int l=0;
            int r=i;
            long long poss=1;
            while(l<=r){
                long long mid=l+((r-l)/2);
                if((i-mid)*((long long)nums[i])-(prefix[i]-prefix[mid])<=k){
                    poss=max(poss,(long long)(i-mid+1));
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            ans=max(ans,poss);
        }
        return ans;
    }
};