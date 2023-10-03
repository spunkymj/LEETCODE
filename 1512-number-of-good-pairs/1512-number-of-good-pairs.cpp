class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &e : nums){
            mp[e]++;
        }
        int ans=0;
        for(auto m : mp){
            int cnt=m.second;
            ans+=((cnt-1)*(cnt))/2;
        }
        return ans;
    }
};