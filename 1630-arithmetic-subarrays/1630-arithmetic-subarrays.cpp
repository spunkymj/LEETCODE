class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
        vector<bool> ans(m,1);
        for(int i=0 ; i<m ; i++){
            vector<int> curr;
            for(int j=l[i] ; j<=r[i] ; j++){
                curr.push_back(nums[j]);
            }
            sort(curr.begin(),curr.end());
            int diff=curr[1]-curr[0];
            for(int k=2 ; k<curr.size() ; k++){
                if(curr[k]-curr[k-1]!=diff){
                    ans[i]=0;
                    break;
                }
            }
        }
        return ans;
    }
};