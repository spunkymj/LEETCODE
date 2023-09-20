class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=0;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            sum+=nums[i];
        }
        int target=sum-x;
        int curr=0;
        int maxi=1e9;
        for(int i=0 , j=0 ; j<n ;j++){
            curr+=nums[j];
            while(i<=j && curr>target){
                curr-=nums[i];
                i++;
            }
            if(curr==target){
                maxi=min(i+(n-1-j),maxi);
            }
        }
        return maxi==1e9 ? -1 : maxi;
    }
};