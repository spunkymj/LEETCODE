class Graph {
public:
    map<int,vector<pair<int,int>>> adj;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        for(auto &v  : edges){
            adj[v[0]].push_back({v[1],v[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  q;      vector<int> dist(n,1e9);
        q.push({0,node1});
        while(!q.empty()){
            int node=q.top().second;
            int cst=q.top().first;
            q.pop();
            if(node==node2){
                return cst;
            }
            for(auto &nbr : adj[node]){
                int new_node=nbr.first;
                int new_cost=nbr.second;
                if(cst+new_cost<=dist[new_node]){
                    dist[new_node]=cst+new_cost;
                    q.push({dist[new_node],new_node});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */