class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int op=0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                i++;
                j--;
                op++;
            }
            else if(nums[i]+nums[j]<k){
                i++;
            }
            else{
                j--;
            }
        }
        return op;
    }
};