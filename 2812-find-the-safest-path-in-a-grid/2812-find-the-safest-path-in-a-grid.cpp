class Solution {
public:
    int n;
    vector<int> dir={-1,0,1,0,-1};

    //Function to check if valid path exists
    bool pathExists(vector<vector<int>> &dis,int val){
        if(dis[0][0]<val){
            return false;
        }
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        q.push({0,0});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r==n-1 && c==n-1){
                return true;
            }
            if(vis[r][c]==1){
                continue;
            }
            vis[r][c]=1;
            for(int d=0 ; d<4 ; d++){
                int nr=r+dir[d];
                int nc=c+dir[d+1];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && dis[nr][nc]>=val){
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,1e9));

        //pushing all thief cells into queue
        queue<pair<int,int>> q;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        //storing minimum manhattan distance for each cell
        int curr=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0 ; i<sz ; i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int d=0 ; d<4 ; d++){
                    int nr=r+dir[d];
                    int nc=c+dir[d+1];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && curr<dis[nr][nc]){
                        dis[nr][nc]=curr;
                        q.push({nr,nc});
                    }
                }
            }
            curr++;
        }

        //Binary Search to check a valid path with given safest factor
        int l=0;
        int r=n*n;
        int ans=0;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(pathExists(dis,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};