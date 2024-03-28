class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int st=0;
        int ans=0;
        int n=nums.size();
        map<int,int> mp;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]]<=k){
                ans=max(ans,i-st+1);
            }
            else{
                while(mp[nums[i]]>k){
                    mp[nums[st]]--;
                    st++;
                }
                ans=max(ans,i-st+1);
            }
        }
        return ans;
    }
};