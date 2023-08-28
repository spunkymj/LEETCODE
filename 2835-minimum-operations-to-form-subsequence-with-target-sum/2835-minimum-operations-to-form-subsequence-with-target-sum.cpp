class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum=accumulate(nums.begin(),nums.end(),(long long)0);
        if(sum<target){
            return -1;
        }
        int op=0;
        sort(nums.begin(),nums.end());
        while(target>0){
            long long curr=nums.back();
            nums.pop_back();
            if(sum-curr>=target){
                sum-=curr;
            }
            else if(curr<=target){
                target-=curr;
                sum-=curr;
            }
            else{
                nums.push_back(curr/2);
                nums.push_back(curr/2);
                op++;
            }
        }
        return op;
    }
};