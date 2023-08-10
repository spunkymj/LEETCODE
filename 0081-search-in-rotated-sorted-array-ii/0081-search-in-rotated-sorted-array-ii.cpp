class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();  
        int l=0;
        int r=n-1;

        //pivot
        if ((nums[l]==nums[r]) && (nums[l]==target)){
            return 1;
        }
        
        while((l+1<n)&&(nums[l+1]==nums[0])){
            l++;
        }
        
        while ((r>=0)&&(nums[r]==nums[0])){
            r--;
        }
        
        int start=l;
        int end=r;
        
        int pivot=-1;
        while(l<=r){
            int mid=l+((r-l)/2);
            if (nums[mid]>=nums[0]){
                l=mid+1;
            }
            else{
                pivot=mid;
                r=mid-1;
            }
        }

        
        if (pivot==-1){
            l=start;
            r=end;
        }
        else if ((target>=nums[pivot]) && ( target<=nums[end])){
            l=pivot;
            r=end;
        }
        else{
            l=start;
            r=pivot-1;
        }
        
        //Binary Search
        while(l<=r){
            int mid=l+((r-l)/2);
            if (nums[mid]==target){
                return 1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    return 0;
    }
};