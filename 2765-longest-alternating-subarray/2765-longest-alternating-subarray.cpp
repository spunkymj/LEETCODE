class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans=0;
        vector<int> val={1,-1};
        for(int i=0 ; i<nums.size()-1 ; i++){
            int j=i+1;
            int id=0;
            if(nums[j]-nums[i]==1){
                while(j<nums.size() && (nums[j]-nums[j-1]==val[id])){
                    j++;
                    id=!id;
                }
                ans=max(ans,j-i);
            }
            j=i-1;
        }
        return ans==0?-1 : ans;
    }
};