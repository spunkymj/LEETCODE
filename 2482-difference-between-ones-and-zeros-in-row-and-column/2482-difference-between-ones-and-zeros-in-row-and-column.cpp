class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> r1(n,0);
        vector<int> c1(m,0);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                r1[i]+=(grid[i][j]);
                c1[j]+=(grid[i][j]);
            }
        }
        vector<vector<int>> diff(n,vector<int> (m,0));
        for(int i=0  ;i<n ; i++){
            for(int j=0 ; j<m ; j++){
                diff[i][j]+=(2*r1[i]+2*c1[j]-n-m);
            }
        }
        return diff;
    }
};