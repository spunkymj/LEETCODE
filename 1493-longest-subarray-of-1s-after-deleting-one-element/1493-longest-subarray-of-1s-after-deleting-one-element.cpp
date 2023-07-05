class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count=0;
        int prev=0;
        int ans=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==1){
                count++;
            }
            else{
                ans=max(ans,count+prev);
                prev=count;
                count=0;
            }
        }
        ans=max(ans,count+prev);
        if(ans==nums.size()){
            ans--;
        }
        return ans;
    }
};