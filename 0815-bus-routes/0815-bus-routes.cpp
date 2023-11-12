class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0 ; i<routes.size() ; i++){
            for(auto v: routes[i]){
                mp[v].push_back(i);
            }
        }
        queue<int> q;
        unordered_set<int> vis;
        for (auto route : mp[source]){
            q.push(route);
            vis.insert(route);
        }
        
        int d=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0 ; i<sz; i ++){
                int curr=q.front();
                q.pop();
                for(auto ele : routes[curr]){
                    if(ele==target){
                        return d;
                    }
                    for(auto &e : mp[ele]){
                        if(vis.find(e)==vis.end()){
                            vis.insert(e);
                            q.push(e);
                        }  
                    }
                }
            }
            d++;
        }

        return -1;
    }
};