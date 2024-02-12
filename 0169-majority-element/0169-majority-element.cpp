class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int prev=nums[0];
        int count=1;
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i]==prev){
                count++;
            }
            else if(count==0){
                prev=nums[i];
                count=1;
            }
            else{
                count--;
            }
        }
        return prev;
    }
};