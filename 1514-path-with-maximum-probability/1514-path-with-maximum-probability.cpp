class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> dis(n,0.00000);
        dis[start]=1.00000;
        vector<vector<pair<double,int>>> adj(n);
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({(double)1.00000,start});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(curr.second==end){
                return curr.first;
            }
            for(auto e : adj[curr.second]){
                double new_prob=curr.first*e.first;
                if(new_prob>dis[e.second]){
                    dis[e.second]=new_prob;
                    pq.push({dis[e.second],e.second});
                }
            }
        }
        return dis[end];
    }
};