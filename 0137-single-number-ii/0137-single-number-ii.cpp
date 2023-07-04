class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> biti(32,0);
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=0 ; j<32 ; j++){
                if(nums[i]&(1<<j)){
                    biti[j]++;
                }
            }
        }
        
        long long ans=0;
        for(int i=0 ; i<32 ; i++){
            if(biti[i]%3==0){
                continue;
            }
            else{
                ans+=(1<<i);
            }
        }
        return ans;
    }
};