class Solution {
public:
    //stores final ans
    vector<int> ans;
    int maxi;
    int maxroot;
    
    //choosing appropriate root
    void rootnode(int root,int dis,vector<vector<int>> &adj,vector<int> &vis){
        if(dis>maxi){
            maxi=dis;
            maxroot=root;
        }
        vis[root]=1;
        for(auto nbr :  adj[root]){
            if(!vis[nbr]){
                rootnode(nbr,dis+1,adj,vis);
            }
        }
    }

    //calculate maximum height between root and leaf node
    int maxheight(int root,vector<vector<int>> &adj,vector<int> &vis){
        int curr=0;
        vis[root]=1;

        //visiting beighbours
        for(auto nbr : adj[root]){
            if(!vis[nbr]){
                curr=max(curr,1+maxheight(nbr,adj,vis));
            }
        }
        return curr;
    }

    //returns maximum height between root node and leaf nodes along with storing    
    //roots which give MHTs 
    int dfs(vector<vector<int>> &adj,vector<int> &vis,int root,int dis,int maxi){
        int curr=0;
        vis[root]=1;

        //visiting beighbours
        for(auto nbr : adj[root]){
            if(!vis[nbr]){
                curr=max(curr,1+dfs(adj,vis,nbr,dis+1,maxi));
            }
        }

        //condition for root which will give MHT
        if(((curr==maxi/2) && (dis==maxi-(maxi/2))) || ((curr==maxi-(maxi/2)) && (dis==maxi/2))){
            ans.push_back(root);
        }

        return curr;
    }


    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //adjacency list
        vector<vector<int>> adj(n);
        for(int i=0 ; i<n-1 ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        //visited array
        vector<int> vis(n,0);
        
        //choosing appropriate root(root which will be part of path with max distance)
        maxi=-1;
        rootnode(0,0,adj,vis);
        cout<<maxroot<<endl;
        
        //marking unvisited
        for(int i=0 ; i<n ; i++){
            vis[i]=0;
        }

        //maxheight from root to leaf node
        int x=maxheight(maxroot,adj,vis);
        cout<<x<<endl;
        
        //marking unvisited
        for(int i=0 ; i<n ; i++){
            vis[i]=0;
        }

        //For getting root which give MHTs
        dfs(adj,vis,maxroot,0,x);

        return ans;
    }
};