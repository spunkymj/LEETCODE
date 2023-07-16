class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> prefix(1e5+1,0);
        for(int i=0 ; i<nums.size() ; i++){
            prefix[max(nums[i]-k,0)]++;
            prefix[min(nums[i]+k+1,(int)1e5)]--;
        }
        int ans=0;
        int curr=0;
        for(auto &e : prefix){
            curr+=e;
            ans=max(ans,curr);
        }
        return ans;
    }
};