class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int left=0;
    int right=nums.size()-1;
    vector<int> x={-1,-1};
    while (left <=right){
        int mid=(left+right)/2;
        if (nums[mid]==target){
            while (((mid-1)>=0) && (nums[mid]==nums[mid-1])){
                mid--;
            }
            x[0]=mid;
            while ((mid+1<nums.size()) && (nums[mid]==nums[mid+1])){
                mid++;
            }
            x[1]=mid;
            return x;
        }
        else if (nums[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return x;
    }
};