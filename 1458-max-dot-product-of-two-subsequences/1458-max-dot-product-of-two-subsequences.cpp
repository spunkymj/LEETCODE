class Solution {
public:
    int maxi(int a,int b,int c){
        return max(max(a,b),c);
    }

    int solve(vector<int> &nums1,vector<int> &nums2,int i,int j,vector<vector<vector<int>>> &dp,int taken){
        if(i==nums1.size() || j==nums2.size()){
            if(taken==0){
                return -1e9;
            }
            return 0;
        }
        if(dp[i][j][taken]!=-1e9){
            return dp[i][j][taken];
        }
        int case1=nums1[i]*nums2[j]+solve(nums1,nums2,i+1,j+1,dp,1);
        int case2=solve(nums1,nums2,i+1,j,dp,taken);
        int case3=solve(nums1,nums2,i,j+1,dp,taken);

        return dp[i][j][taken]=maxi(case1,case2,case3);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m,vector<int>(2,-1e9)));
        return solve(nums1,nums2,0,0,dp,0);
    }
};