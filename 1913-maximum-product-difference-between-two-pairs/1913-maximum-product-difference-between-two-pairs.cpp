#define all(x) x.begin(),x.end()

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(all(nums));
        int n=nums.size();
        return (nums[n-1]*nums[n-2])-(nums[0]*nums[1]);
    }
};