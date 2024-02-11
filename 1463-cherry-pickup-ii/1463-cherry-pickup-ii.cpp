class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        
        for(int j1=0 ; j1<m ; j1++){
            for(int j2=0 ; j2<m ; j2++){
                if(j1==j2){
                    dp[n-1][j1][j2]=grid[n-1][j1];
                }
                else{
                    dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
        
        for(int i=n-2 ; i>=0 ; i--){
            for(int j1=0 ; j1<m ; j1++){
                for(int j2=0 ; j2<m ; j2++){
                    int maxi=0;
                    for(int k=-1 ; k<=1 ; k++){
                        for(int l=-1 ; l<=1 ; l++){
                        int c=0;
                        if(j1+k>=0 && j1+k<m && j2+l>=0 && j2+l<m){
                            if(j1==j2 ){
                                c=grid[i][j1]+dp[i+1][j1+k][j2+l];
                            }
                            else{
                                c=grid[i][j1]+grid[i][j2]+dp[i+1][j1+k][j2+l];
                            }
                        }
                        maxi=max(maxi,c);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};