class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n+1,0);
        for(int i=0 ; i<n ; i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        vector<int> res;
        for(int i=0 ; i<n ; i++){
            int r=prefix[n]-prefix[i+1];
            int l=prefix[i];
            int x=r-(nums[i]*(n-i-1));
            x+=nums[i]*(i)-l;
            res.push_back(x);
        }
        return res;
    }
};