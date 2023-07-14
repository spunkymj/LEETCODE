class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> mp;
        int n=arr.size();
        vector<int> dp(n,1);
        int ans=0;
        for(int i=0 ; i<n ; i++){
            if(mp.count(arr[i]-difference)){
                dp[i]=1+dp[mp[arr[i]-difference]];
            }
            mp[arr[i]]=i;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};