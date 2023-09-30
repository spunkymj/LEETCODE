class Solution {
public:
    int dfs(int node,int par,int &ans,vector<vector<int>> &adj,vector<int> &values,int k){
        int sum=values[node];
        for(auto nbr : adj[node]){
            if(nbr!=par){
                sum+=dfs(nbr,node,ans,adj,values,k);
            }
        }
        if(sum%k==0){
            ans++;
            return 0;
        }
        else{
            return sum%k;
        }
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int ans=0;
        dfs(0,0,ans,adj,values,k);
        return ans;
    }
};