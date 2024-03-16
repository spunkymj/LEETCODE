class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        int zero=0;
        int one=0;
        int ans=0;
        mp[0]=-1;
        for(int i=0 ; i<n ; i++){
            zero+=(nums[i]==0);
            one+=(nums[i]==1);
            if(mp.count(one-zero)){
                ans=max(ans,(i-mp[one-zero]));
            }
            else{
                mp[one-zero]=i;
            }
        }
        
        return ans;
    }
};