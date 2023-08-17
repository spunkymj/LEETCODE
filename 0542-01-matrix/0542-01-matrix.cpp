class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j]==0){
                    vis[i][j]=true;
                    q.push({{i,j},0});
                }
            }
        }
        vector<int> dir={-1,0,1,0,-1};
        while(!q.empty()){
            int cr=q.front().first.first;
            int cc=q.front().first.second;
            int dis=q.front().second;
            ans[cr][cc]=dis;
            q.pop();
            for(int i=0 ; i<4 ; i++){
                int nr=cr+dir[i];
                int nc=cc+dir[i+1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},dis+1});
                }
            }
        }
        return ans;
    }
};