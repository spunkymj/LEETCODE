class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& a) {
        int n=a.size();
        n++;
        map<int,vector<int>> adj;
        for(auto &v : a){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int start=-1;
        for(auto m : adj){
            int i=m.first;
            if(adj[i].size()==1){
                start=i;
                break;
            }
        }

        vector<int> ans;
        ans.push_back(start);
        map<int,int> vis;
        vis[start]=1;
        for(int i=0 ; i<n-1 ;i++){
            if(!vis[adj[start][0]]){
                start=adj[start][0];
                vis[start]=1;
            }
            else if(!vis[adj[start][1]]){
                start=adj[start][1];
                vis[start]=1;
            }
            ans.push_back(start);
        }
        return ans;
    }
};