class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int i=0;
        int j=1;
        for(int idx=0 ; idx < n ; idx++){
            if(nums[idx]>0){
                ans[i]=nums[idx];
                i+=2;
            }
            else{
                ans[j]=nums[idx];
                j+=2;
            }
        }
        return ans;
    }
};