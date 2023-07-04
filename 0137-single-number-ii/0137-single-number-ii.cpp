class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitpos(32,0),bitneg(32,0);
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>=0){
                for(int j=0 ; j<32 ; j++){
                    if(nums[i]&(1<<j)){
                        bitpos[j]++;
                    }
                }
            }
            else{
                for(int j=0 ; j<32 ; j++){
                    if(nums[i]&(1<<j)){
                        bitneg[j]++;
                    }
                }
            }
        }
        
        long long ans=0;
        bool neg=false;
        for(int i=0 ; i<32 ; i++){
            if(bitpos[i]%3==0 && bitneg[i]%3==0){
                continue;
            }
            else{
                if(bitneg[i]%3!=0){
                    neg=true;
                    ans+=(1<<i);
                }
                else{
                    ans+=(1<<i);
                }
            }
        }
        return ans;
    }
};