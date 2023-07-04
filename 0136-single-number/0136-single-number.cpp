class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto &e : nums){
            ans=ans^e;
        }
        return ans;
    }
};