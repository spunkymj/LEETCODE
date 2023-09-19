class Solution {
public:
    //The intuition is that for a node and it's parent ,
    //All edges directed towards parent are also directed towards node except the edge between parent and node
    //If there is edge from parent to node then it's directed towards node but directed away the parent and vice-versa
    //The ans for any node is simply number of edges directed towards the node.
    
    
    //for every node, this dfs function gives number of children edges directed towards the node.
    int dfs(int node,vector<vector<int>> &adj,vector<int> &vis,map<pair<int,int>,int> &mp){
        
        vis[node]=1;
        int willReverse=0;
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                willReverse+=mp[make_pair(nbr,node)]+dfs(nbr,adj,vis,mp);
            }
        }
        
        return willReverse;
    }
    
    
    //This dfs helps calculate the ans for each node.
    //ans for each node just depends on ans of parent node
    //if there is directed edge from parent node to child node , then ans[child]=ans[parent]+1
    //otherwise there would be directed edge from child node to parent node and then ans[child]=ans[parent]-1;
    void dfs2(int node,vector<vector<int>> &adj,vector<int> &vis,map<pair<int,int>,int> &mp,vector<int> &ans){
        vis[node]=1;
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                if(mp[make_pair(node,nbr)]){
                    ans[nbr]=ans[node]+1;
                }
                else{
                    ans[nbr]=ans[node]-1;
                }
                dfs2(nbr,adj,vis,mp,ans);
            }
        }
        
        return ;
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        //map to keep track of directed edges , so that dfs can be performed as an undirected graph .
        map<pair<int,int>,int> mp;
        
        //adjacency vector
        vector<vector<int>> adj(n);
        for(int i=0 ; i<n-1 ; i++){
            mp[make_pair(edges[i][0],edges[i][1])]=1;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        //keeps track of visited nodes
        vector<int> vis(n,0);
        vector<int> ans(n,0);
        ans[0]=dfs(0,adj,vis,mp);
        for(int i=0 ; i<n ; i++){
            vis[i]=0;
        }
        
        dfs2(0,adj,vis,mp,ans);
        return ans;
        
    }
};