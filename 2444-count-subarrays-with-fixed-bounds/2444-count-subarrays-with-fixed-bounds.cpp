class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int miniidx=-1,maxiidx=-1;
        int start=0;
        bool chkmaxi=false,chkmini=false;
        long long ans=0;
        for(int i=0 ; i<nums.size()  ; i++){
            if(nums[i]>maxK || nums[i]<minK){
                start=i+1;
                chkmaxi=false;
                chkmini=false;
            }
            
            if(nums[i]==maxK){
                chkmaxi=true;
                maxiidx=i;
            }
            if(nums[i]==minK){
                chkmini=true;
                miniidx=i;
            }
            if(chkmaxi && chkmini){
                ans+=(min(maxiidx,miniidx)-start+1);
            }
        }
        return ans;
    }
};