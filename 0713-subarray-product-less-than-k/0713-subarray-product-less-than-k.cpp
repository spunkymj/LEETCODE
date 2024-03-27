class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int one=0;
        int ans=0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]==1){
                one++;
                continue;
            }
            int p=1;
            int j=i;
            for(j ; j<n ; j++){
                p*=nums[j];
                if(p>=k){
                    break;
                }
            }
            ans+=(one+1)*(j-i);
            if(k>1){
                ans+=(one*(one+1))/2;
            }
            one=0;
        }
        if(k>1){
            ans+=(one)*(one+1)/2;
        }
        return ans;
    }
};