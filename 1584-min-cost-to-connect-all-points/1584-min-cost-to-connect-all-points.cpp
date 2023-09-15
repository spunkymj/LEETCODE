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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> edges;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dis,i,j});
            }
        }
        DS dsu(n);
        int ans=0;
        sort(edges.begin(),edges.end());
        for(int i=0 ; i<edges.size() ; i++){
            int x=edges[i][1];
            int y=edges[i][2];
            int wt=edges[i][0];
            if(dsu.find(x)!=dsu.find(y)){
                ans+=wt;
                dsu.union_size(x,y);
            }
        }
        return ans;
    }
};