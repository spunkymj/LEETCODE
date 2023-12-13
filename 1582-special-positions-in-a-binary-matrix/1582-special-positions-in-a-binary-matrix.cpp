class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> r(n,0);
        vector<int> c(m,0);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                r[i]+=mat[i][j];
                c[j]+=mat[i][j];
            }
        }
        int ans=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                ans+=(mat[i][j] && (r[i]==1) && (c[j]==1));
            }
        }
        return ans;
    }
};