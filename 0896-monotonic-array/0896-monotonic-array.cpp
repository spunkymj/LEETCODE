class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc=0;
        int dec=0;
        int n=nums.size();
        for(int i=1 ; i<n ; i++){
            if(nums[i]>=nums[i-1]){
                dec++;
            }
            if(nums[i]<=nums[i-1]){
                inc++;
            }
        }
        return (inc==n-1 || dec==n-1);
    }
};