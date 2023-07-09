class Solution {
public:
    bool checkArray(vector<int>& nums, int k){
        int n=nums.size();
        vector<int> d(n+1,0);
        for(int i=0 ; i<n ; i++){
            if(i>0){
                d[i]+=d[i-1];
            }
            int diff=nums[i]-d[i];
            if(diff<0){
                return false;
            }
            if(i+k>n){
                if(diff!=0){
                    return false;
                }
                else{
                    continue;
                }
            }
            d[i]+=diff;
            d[i+k]-=diff;
        }
        return true;
    }
};