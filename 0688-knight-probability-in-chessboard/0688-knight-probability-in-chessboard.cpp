class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<int> r={-2,-1,1,2,-2,-1,1,2};
        vector<int> c={-1,-2,-2,-1,1,2,2,1};
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n,vector<double>(n,0)));
        dp[0][row][column]=1;
        for(int m=1 ; m<=k ; m++){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    for(int d=0 ; d<8 ; d++){
                        int pr=i-r[d];
                        int pc=j-c[d];
                        if(pr>=0 && pr<n && pc>=0 && pc<n ){
                            dp[m][i][j]+=dp[m-1][pr][pc]/8;
                        }
                    }
                }
            }
        }
        double prob=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                prob+=dp[k][i][j];
            }
        }
        return prob;
    }
};