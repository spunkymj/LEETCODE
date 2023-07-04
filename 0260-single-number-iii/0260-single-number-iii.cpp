class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(auto &e : nums){
            x=x^e;
        }
        
        int i=0;
        for(; i<32 ; i++){
            if(x&(1<<i)){
                break;
            }
        }

        int xor1=0;
        int xor2=0;
        for(auto &e : nums){
            if(e&(1<<i)){
                xor1=xor1^e;
            }
            else{
                xor2=xor2^e;
            }
        }
        
        return {xor1,xor2};
    }
};