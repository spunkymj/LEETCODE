class Solution {
public:
    int bs(vector<int> nums,int left, int right , int target){
        while( left<=right){
            int mid=left+((right-left)/2);
            if (nums[mid]==target){
                return mid;
            }
            else if (nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return -1;
    }
    
    int pivot(vector<int> nums , int n ){
        int left=0;
        int right=n-1;
        int mid=0;
        while(left<right){
            mid=left+((right-left)/2);
            if (nums[mid]>=nums[0]){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return right;
    }
    
    
    int search(vector<int>& nums, int target) {
    int n=nums.size();
    
    int p=pivot(nums,n);
    if ( (target>=nums[p]) && (target<=nums[n-1])){ 
        return bs(nums,p,n-1,target);
    }
    else{
        return bs (nums ,0 ,p-1 , target);
    }
    }
};