class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        vector<int> indeg(n+1,0);
        vector<vector<int>> adj(n+1);
        for(auto &v : rel){
            adj[v[0]].push_back(v[1]);
            indeg[v[1]]++;
        }
        queue<pair<int,int>> q;
        for(int i=1 ; i<=n ; i++){
            if(indeg[i]==0){
                q.push({i,time[i-1]});
            }
        }
        vector<int> dis(n+1,0);
        int ans=0;
        while(!q.empty()){
            int curr=q.front().first;
            int t=q.front().second;
            q.pop();
            ans=max(ans,t);
            for(auto &nbr  : adj[curr]){
                indeg[nbr]--;
                dis[nbr]=max(dis[nbr],t);
                if(indeg[nbr]==0){
                    q.push({nbr,dis[nbr]+time[nbr-1]});
                }
            }
        } 
        return ans;
    }
};