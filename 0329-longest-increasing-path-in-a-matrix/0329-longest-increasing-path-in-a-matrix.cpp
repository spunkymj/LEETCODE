class Solution {
public:
    vector<int> dir={-1,0,1,0,-1};
    int solve(vector<vector<int>>& matrix,int r,int c,int &n,int &m,vector<vector<int>> &dp){
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int ans=0;
        for(int i=0 ; i<4 ; i++){
            int nr=r+dir[i];
            int nc=c+dir[i+1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]>matrix[r][c]){
                ans=max(ans,1+solve(matrix,nr,nc,n,m,dp));
            }
        }
        return dp[r][c]=ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                ans=max(ans,solve(matrix,i,j,n,m,dp));
            }
        }
        return ans+1;     
    }
};