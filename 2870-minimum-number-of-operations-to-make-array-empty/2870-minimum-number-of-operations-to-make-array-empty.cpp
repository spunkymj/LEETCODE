class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto e : nums){
            mp[e]++;
        }
        int ans=0;
        for(auto m : mp){
            if(m.second==1){
                return -1;
            }
            ans+=(m.second+2)/3;
        }
        return ans;
    }
};