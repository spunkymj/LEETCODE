class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> dist(1<<n , vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> pq;
        for(int i=0 ; i<n ; i++){
            pq.push({0,{i,1<<i}});
        }
        while(!pq.empty()){
            int node=pq.front().second.first;
            int vis=pq.front().second.second;
            int dis=pq.front().first;
            pq.pop();
            if(vis==(1<<n)-1){
                return dis;
            }
            for(auto nbr  : graph[node]){
                if(dis+1<dist[vis][nbr]){
                    dist[vis][nbr]=dis+1;
                    pq.push({dis+1,{nbr,(vis|(1<<nbr))}});
                }
            }
        }
        return 0;
    }
};