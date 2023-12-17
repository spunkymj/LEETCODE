class Solution {
public:
    bool bs(vector<long long> &prefix,vector<int> &nums,long long l,long long r,long long k){
        long long m=(l+r)/2;
        long long cost=(m-l+1)*nums[m]-(prefix[m+1]-prefix[l]);
        cost+=(prefix[r+1]-prefix[m+1])-(r-m)*(nums[m]);
        return cost<=k;
    }

    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        long long n=nums.size();
        vector<long long> prefix(n+1,0);
        for(int i=0 ; i<n ; i++){
            prefix[i+1]+=prefix[i]+(long long)nums[i];
        }

        int ans=1;

        int st=0;
        for(int i=0 ; i<n ; i++){
            if(i<n && !bs(prefix,nums,st,i,k)){
                st++;
            }
            ans=max(ans,i-st+1);
        }
        return ans;
    }
};