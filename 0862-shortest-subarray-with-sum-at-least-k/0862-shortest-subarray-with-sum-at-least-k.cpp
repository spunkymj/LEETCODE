class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        set<pair<long long,int>> st;
        int n=nums.size();
        long long prefix=0;
        int ans=1e9;
        for(int i=0 ; i<n ; i++){
            prefix+=nums[i];
            st.insert({prefix,i});
            while(!st.empty() && prefix-st.begin()->first>=k){
                ans=min(ans,i-st.begin()->second);
                st.erase(st.begin());
            }
            if(prefix>=k){
                ans=min(ans,i+1);
            }
        }
        return ans==1e9 ? -1 : ans;
    }
};