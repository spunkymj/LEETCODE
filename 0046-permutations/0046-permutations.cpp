class Solution {
public:
    void solve(vector<int> &nums,int idx, vector<vector<int>> &ans){
        if(idx==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i=idx ; i<nums.size() ; i++){
            swap(nums[i],nums[idx]);
            solve(nums,idx+1,ans);
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};