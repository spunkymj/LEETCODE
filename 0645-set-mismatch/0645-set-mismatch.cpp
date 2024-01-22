class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> f;
        for(auto e : nums){
            f[e]++;
        }
        vector<int> ans(2,0);
        for(int i=1 ; i<=nums.size() ; i++){
            if(f[i]==0){
                ans[1]=i;
            }
            if(f[i]==2){
                ans[0]=i;
            }
        }
        return ans;
    }
};