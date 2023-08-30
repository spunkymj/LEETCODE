class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        int last=nums[n-1];
        long long steps=0;
        for(int i=n-2 ; i>=0 ; i--){
            long long step=(nums[i]-1)/last;
            steps+=step;
            if(step>=1){
                last=(nums[i])/(step+1);
            }
            else{
                last=nums[i];
            }
        }
        return steps;
    }
};