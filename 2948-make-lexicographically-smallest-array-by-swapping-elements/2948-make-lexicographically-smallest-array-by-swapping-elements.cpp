
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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        DS dsu(n);
        vector<int> trav(n,0);
        for(int i=0 ; i<n ; i++){
            trav[i]=i;
        }
        sort(trav.begin(),trav.end(),[&](int i,int j){
            return nums[i]<nums[j];
        });
        
        for(int i=1 ; i<trav.size() ; i++){
            if(nums[trav[i]]-nums[trav[i-1]]<=limit){
                dsu.union_size(trav[i],trav[i-1]);
            }
        }
        map<int,multiset<int>> mp;
        for(int i=0 ; i<n ; i++){
            mp[dsu.find(i)].insert(nums[i]);
        }
        vector<int> res;
        for(int i=0 ; i<n ; i++){
            res.push_back(*mp[dsu.find(i)].begin());
            mp[dsu.find(i)].erase(mp[dsu.find(i)].begin());
        }
        return res;
    }
};