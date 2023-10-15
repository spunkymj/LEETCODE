class Solution {
public:
    int mod=12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<long long> prefix_r(n+1,1);
        for(int i=0  ; i<n ; i++){
            long long p=1;
            for(int j=0 ; j<m ; j++){
                p%=mod;
                p*=(long long)grid[i][j];
                p%=mod;
            }
            prefix_r[i+1]=p;
            prefix_r[i+1]%=mod;
            prefix_r[i+1]*=prefix_r[i];
            prefix_r[i+1]%=mod;
        }

        vector<long long> suffix_r(n+1,1);
        for(int i=n-1  ; i>=0 ; i--){
            int p=1;
            for(int j=0 ; j<m ; j++){
                p*=(long long)grid[i][j];
                p%=mod;
            }
            suffix_r[i]=p;
            suffix_r[i]%=mod;
            suffix_r[i]*=suffix_r[i+1];
            suffix_r[i]%=mod;
        }

        vector<vector<int>> ans(n,vector<int>(m,1));
        for(int i=0 ; i<n ; i++){
            vector<long long> prefix(m+1,1);
            vector<long long> suffix(m+1,1);
            for(int j=0 ; j<m ; j++){
                prefix[j+1]=(long long)grid[i][j];
                prefix[j+1]%=mod;
                prefix[j+1]*=prefix[j];
                prefix[j+1]%=mod;
            }
            for(int j=m-1 ; j>=0 ; j--){
                suffix[j]=(long long)grid[i][j];
                suffix[j]%=mod;
                suffix[j]*=suffix[j+1];
                suffix[j]%=mod;
            }

            for(int j=0 ; j<m ; j++){
                ans[i][j]=(((prefix_r[i]*suffix_r[i+1])%mod)*prefix[j])%mod*suffix[j+1];
                ans[i][j]%=mod;
            }
        }

        return ans;
    }
};