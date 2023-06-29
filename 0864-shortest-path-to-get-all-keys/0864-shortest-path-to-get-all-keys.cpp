class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(!n || !m) return 0;
        int path=0, k=0;
        vector<int> dirs={0,-1,0,1,0};
        vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m,vector<bool>(64,0))); //at most 6 keys, using bitmap 111111
        
        queue<pair<int,int>> q; //<postion, hold keys mapping>
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    q.push({i*m+j,0});
                    visited[i][j][0]=1;                    
                }
                if(grid[i][j]>='a' && grid[i][j]<='f') k++; //total keys
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int r=q.front().first/m;
                int c=q.front().first%m;
                int carry=q.front().second;
                q.pop();        
                if(carry==((1<<k)-1)) return path; //if all keys hold, just return 
                for(int j=0;j<4;j++){
                    int nr=r+dirs[j];
                    int nc=c+dirs[j+1];
                    int k=carry;
                    if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]=='#') continue;
                    if(grid[nr][nc]>='a' && grid[nr][nc]<='f'){
                        k=carry|(1<<(grid[nr][nc]-'a')); //update hold keys
                    }
                    else if(grid[nr][nc]>='A' && grid[nr][nc]<='F'){
                        if(!(carry & (1<<(grid[nr][nc]-'A')))) continue;
                    }
                    if(!visited[nr][nc][k]){
                        visited[nr][nc][k]=1;
                        q.push({nr*m+nc,k});
                   }                
                }
            }
            path++;
        }
        return -1;
    }
};