class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ptr=n-1;
        while(ptr-1>=0 && nums[ptr]<=nums[ptr-1]){
            ptr--;
        }
        if(ptr==0){
            sort(nums.begin(),nums.end());
            return;
        }
        int id=ptr;
        int maxi=nums[ptr];
        for(int i=ptr ; i<n ; i++){
            if(nums[i]>nums[ptr-1]){
                if(nums[i]<maxi){
                    maxi=nums[ptr];
                    id=i;
                }
            }
        }
        swap(nums[ptr-1],nums[id]);
        sort(nums.begin()+ptr,nums.end());
    }
};