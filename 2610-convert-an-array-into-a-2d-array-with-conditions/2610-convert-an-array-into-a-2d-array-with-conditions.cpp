class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi=0;
        for(auto c : nums){
            mp[c]++;
            maxi=max(maxi,mp[c]);
        }
        vector<vector<int>> ans(maxi);
        for(auto e : mp){
            int ptr=0;
            for(int i=0 ; i<e.second ; i++){
                ans[ptr].push_back(e.first);
                ptr++;
            }
        }
        return ans;
        
    }
};