class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto e  : nums){
            mp[e]++;
        }
        int curr=0;
        int ans=0;
        for(auto m : mp){
            ans+=curr*(m.second);
            curr++;
        }
        return ans;
    }
};