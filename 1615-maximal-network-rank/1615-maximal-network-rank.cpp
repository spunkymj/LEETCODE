class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(int i=0 ; i<roads.size() ; i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        int ans=0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                bool chk=false;
                for(auto e : adj[j]){
                    if(e==i){
                        chk=true;
                        break;
                    }
                }
                ans=max(ans,(int)adj[i].size()+(int)adj[j].size()-chk);
            }
        }
        return ans;
    }
};