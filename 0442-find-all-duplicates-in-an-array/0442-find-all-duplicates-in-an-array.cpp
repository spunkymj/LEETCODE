class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> x;
        int ans=0;
        for(int i=0;i<n;i++){
            int index = abs(nums[i])-1;
            if(nums[index]<0) {
                x.push_back(index+1);
                continue;
            }
            nums[index]= -nums[index];
        }    
        return x;
    }
};