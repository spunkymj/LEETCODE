class DS
{
  vector<int> rank, parent, size;

public:
  DS(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int node)
  {
    if (node == parent[node])
      return node;
    return parent[node] = find(parent[node]);
  }

  void union_rank(int u, int v)
  {
    int ulp_u = find(u);
    int ulp_v = find(v);
    if (ulp_u == ulp_v)
      return;
    if (rank[ulp_u] < rank[ulp_v])
    {
      parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u])
    {
      parent[ulp_v] = ulp_u;
    }
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  void union_size(int u, int v)
  {
    int ulp_u = find(u);
    int ulp_v = find(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l=0;
        int r=cells.size()-1;
        vector<int> dir={-1,0,1,0,-1};
        int ans=0;
        while(l<=r){
          int mid=l+((r-l)/2);
          vector<vector<int>> grid(row+1,vector<int>(col+1,0));
          for(int i=0 ; i<=mid ; i++){
            int r=cells[i][0];
            int c=cells[i][1];
            grid[r][c]=1;
          }
          DS ds((row+1)*(col+1)+1);
          for(int r=1 ; r<=row ; r++){
            for(int c=1 ; c<=col ; c++){
              if(grid[r][c]==1){
                continue;
              }
              int cell1=r*(col+1)+c;
              for(int k=0 ; k<4 ; k++){
                int nr=r+dir[k];
                int nc=c+dir[k+1];
                if(nr>=1 && nr<=row && nc>=1 && nc<=col && grid[nr][nc]==0){
                  int cell2=nr*(col+1)+nc;
                  ds.union_size(cell1,cell2);
                }
              }
            }
          }
          int par1,par2;
          unordered_map<int,int> mp;
          for(int i=1;i<=col;i++){
            if(grid[1][i]==1){
              continue;
            }
            int val=1*(col+1)+i;
            mp[ds.find(val)]=1;
          }
          bool chk=false;
          for(int i=1;i<=col;i++){
            if(grid[row][i]==1){
              continue;
            }
            int val=row*(col+1)+i;
            if(mp[ds.find(val)]){
              chk=true;
              break;
            }
          }
          if(chk){
            ans=max(ans,mid+1);
            l=mid+1;
          }
          else{
            r=mid-1;
          }
        }
        return ans;
    }
};