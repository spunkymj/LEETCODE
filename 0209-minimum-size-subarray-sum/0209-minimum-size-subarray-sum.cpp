class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int curr=0;
        int j=0;
        for( int i=0 ; i<nums.size() ; i++){
            curr+=nums[i];
            while(curr>=target){
                ans=min(ans,i-j+1);
                curr-=nums[j++];
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};