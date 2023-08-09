class Solution {
public:
    bool check(vector<int>& nums, int p,int k){
        int n=nums.size();
        int c=0;
        for(int i=0 ; i<n-1 ; i++){
            if(abs(nums[i]-nums[i+1])<=k){
                c++;
                i++;
            }
        }
        return c>=p?true : false;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums[nums.size()-1];
        int ans=0;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(check(nums,p,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};