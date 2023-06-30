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
        DS ds(row*col+2);
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int i=0 ; i<cells.size() ; i++){
            int r=cells[i][0]-1;
            int c=cells[i][1]-1;
            grid[r][c]=1;
            int val1=r*(col)+c;

            //connecting neighbours which are also 1(water)
            for(int k=-1 ; k<=1 ; k++){
              for(int kk=-1 ; kk<=1 ; kk++){
                  if(k==0 && kk==0){
                    continue;
                  }
                  int nr=r+k;
                  int nc=c+kk;
                  if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==1){
                      int val2=nr*col+nc;
                      ds.union_size(val1,val2);
                  }
              }
            }
            
            
            //if there is a path from 0th col to (m-1)th col then not possible to go
            //from first row to last row
            if(c==0){
                ds.union_size(val1,row*col);
            }

            if(c==col-1){
                ds.union_size(val1,row*col+1);
            }

            if(ds.find(row*col)==ds.find(row*col+1)){
                return i;
            }
        }
        return -1;
    }
};