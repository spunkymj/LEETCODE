class Solution {
public:
    
    //storing nodes in cycle which form the key(identify a unique cycle) for a cycle 
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &cycle,vector<int> &cycled){
        vis[node]=1;
        cycled[node]=1;
        for(auto nbr  : adj[node]){
            if(vis[nbr]){
                if(cycled[nbr]==1){
                    cycle.push_back(nbr);
                }
            }
            else{
                dfs(nbr,adj,vis,cycle,cycled);
            }
        }
        cycled[node]=0;
        
    }
    
    //storing all nodes belonging to a cycle with an assigned key
    void dfs2(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &help){
        vis[node]=1;
        help.push_back(node);
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                dfs2(nbr,adj,vis,help);
            }
        }
        
    }
    
    //storing ans for non-cycle elements
    void dfs3(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &ans,int curr){
        vis[node]=1;
        ans[node]+=curr;
        for(auto nbr  : adj[node]){
            if(!vis[nbr]){
               dfs3(nbr,adj,vis,ans,curr+1);
            }
        }
        
    }
    
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        //graph
        vector<vector<int>> adj(n);
        //reverse graph for storing ans for non-cycle elements
        vector<vector<int>> revadj(n);
        
        for(int i=0 ; i<n ; i++){
            adj[i].push_back((int)edges[i]);
            revadj[edges[i]].push_back(i);
        }
        vector<int> vis(n,0);
        vector<int> cycle;
        vector<int> cycled(n,0);
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,adj,vis,cycle,cycled);
            }
        }

        for(int i=0 ; i<n ; i++){
            vis[i]=0;
        }
        
        //storing all cycle elements
        vector<vector<int>> help(n);
        for(auto e : cycle){
            dfs2(e,adj,vis,help[e]);
        }

        vector<int> ans(n,0);
        //storing ans for cycle elements
        for(int i=0 ; i<n ; i++){
            for(auto j : help[i]){
                ans[j]=help[i].size();
            }
        }
        
        //storing ans for non-cycle elements
        for(int i=0 ; i<n ; i++){
            for(auto j : help[i]){
                for(auto nbr : revadj[j]){
                    if(!vis[nbr]){
                        dfs3(nbr,revadj,vis,ans,help[i].size()+1);
                    }
                }
            }
        }
        return ans;
    }
};