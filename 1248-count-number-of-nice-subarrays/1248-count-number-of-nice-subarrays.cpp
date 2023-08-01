class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> pos;
        int n=nums.size();
        if(k==0){
            return n*(n+1)/2;
        }
        pos.push_back(-1);
        for(int i=0 ; i<n ; i++){
            if(nums[i]&1){
                pos.push_back(i);
            }
        }
        int ans=0;
        if(pos.size()>1){
            pos.push_back(n);
            for(int i=1 ; i+k<pos.size() ; i++){
                ans+=(pos[i]-pos[i-1])*(pos[i+k]-pos[i+k-1]);
            }
        }
        return ans;
    }
};