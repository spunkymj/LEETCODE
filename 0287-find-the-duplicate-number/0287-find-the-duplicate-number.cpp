class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0 ; i<n ; i++){
            int curr=abs(nums[i]);
            if(nums[curr]<0){
                for(int i=0 ; i<n ; i++){
                    nums[i]=abs(nums[i]);
                }
                return curr;
            }
            nums[curr]=(-1)*nums[curr];
        }
        return 0;
    }
};