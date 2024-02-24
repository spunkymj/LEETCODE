class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int f) {
        vector<int> knows(n,0);
        knows[0]=1;
        knows[f]=1;
        map<int,vector<pair<int,int>>> m;
        for(auto &v : meetings){
            m[v[2]].push_back({v[0],v[1]});
        }
        for(auto &v : m){
            map<int,vector<int>> adj;
            for(auto &p : v.second){
                adj[p.first].push_back(p.second);
                adj[p.second].push_back(p.first);
            }
            queue<int> q;
            map<int,int> vis;
            for(auto e : adj){
                if(knows[e.first]){
                    q.push(e.first);
                }
            }
            while(!q.empty()){
                int curr=q.front();
                vis[curr]=1;
                q.pop();
                for(auto nbr : adj[curr]){
                    if(!vis[nbr]){
                        vis[nbr]=1;
                        knows[nbr]=1;
                        q.push(nbr);
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            if(knows[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};