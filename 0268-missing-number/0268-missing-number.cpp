class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int last=0;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            if(nums[i]%(n+1)==n){
                last=-1;
                continue;
            }
            nums[nums[i]%(n+1)]=(n+1)+nums[nums[i]%(n+1)];
        }
        if(last==0){
            return n;
        }
        for(int i=0 ; i<n ; i++){
            if(nums[i]<=n){
                return i;
            }
        }
        return 0;
    }
};