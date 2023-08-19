class Solution {
public:
    bool isvalid(vector<int> &bit,int curr){
        for(int k=0 ; k<31 ; k++){
            bit[k]+=(((1<<k)&curr)>0);
        }
        for(int i=0 ; i<31 ; i++){
            if(bit[i]>1){
                return false;
            }
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        vector<int> bit(31,0);
        int ans=0;
        while(j<n){
            while(j<n && isvalid(bit,nums[j])){
                j++;
            }
            ans=max(ans,j-i);
            for(int k=0 ; k<31 ; k++){
                bit[k]-=(((1<<k)&nums[i])>0);
            }
            i++;
            j++;
        }
        return ans;
    }
};