class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        int curr=0,ans=0;
        mp[0]=1;
        for(auto &e : nums){
            curr+=e;
            ans+=(mp[curr-goal]);
            mp[curr]++;
        }
        return ans;
    }
};