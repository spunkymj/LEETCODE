class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        map<int,vector<int>> mp;
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=0 ; j<nums[i].size() ; j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(auto &m : mp){
            for(auto &e : m.second){
                ans.push_back(e);
            }
        }
        return ans;
    }
};