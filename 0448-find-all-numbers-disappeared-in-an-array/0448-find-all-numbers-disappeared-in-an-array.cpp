class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            int current_index=abs(nums[i])-1;
            if(nums[current_index]<0){
                continue;
            }
            nums[current_index]=(-1)*nums[current_index];
        }
        for(int i=0 ; i<n ; i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};