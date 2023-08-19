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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<int> trav(m,0);
        iota(trav.begin(),trav.end(),0);
        sort(trav.begin(),trav.end(),[&](int i , int j ){
            return edges[i][2]<edges[j][2];
        });

        DS ds(n);
        int mst=0;
        for(auto e : trav){
            if(ds.find(edges[e][0])!=ds.find(edges[e][1])){
                ds.union_size(edges[e][0],edges[e][1]);
                mst+=edges[e][2];
            }
        }

        vector<vector<int>> ans(2);
        for(int i=0 ; i<m ; i++){
          DS dsu(n);
          int curr_mst=0;
          for(auto e : trav){
              if(e==i){
                continue;
              }
              if(dsu.find(edges[e][0])!=dsu.find(edges[e][1])){
                  dsu.union_size(edges[e][0],edges[e][1]);
                  curr_mst+=edges[e][2];
              }
          }
          int par=dsu.find(0);
          bool chk=false;
          for(int i=0 ; i<n ; i++){
            if(dsu.find(i)!=par){
              chk=true;
            }
          }
          if(chk || curr_mst!=mst){
            ans[0].push_back(i);
          }
          else{
            DS dsu2(n);
            curr_mst=0;
            dsu2.union_size(edges[i][0],edges[i][1]);
            curr_mst+=edges[i][2];
            for(auto e : trav){
                if(e==i){
                  continue;
                }
                if(dsu2.find(edges[e][0])!=dsu2.find(edges[e][1])){
                    dsu2.union_size(edges[e][0],edges[e][1]);
                    curr_mst+=edges[e][2];
                }
            }
            if(curr_mst==mst){
              ans[1].push_back(i);
            }
          }
        }
        
        return ans;
    }
};