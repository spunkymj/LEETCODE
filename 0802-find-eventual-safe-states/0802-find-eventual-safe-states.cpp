class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>> adj(V);
        vector<int> ind(V,0);
        for(int i=0 ; i<V;  i++){
            for(auto n : graph[i]){
                adj[n].push_back(i);
                ind[i]++;
            }
        }
        queue<int> q;
        for(int i=0 ; i<V;  i++){
            if(ind[i]==0){
                q.push(i);
            }
        }	   
        vector<int> ans;
	    while(!q.empty()){
	        int node=q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto  a: adj[node]){
	            ind[a]--;
	            if(ind[a]==0){
	                q.push(a);
	            }
	        }
	    }
        sort(ans.begin(),ans.end());
        return ans;
    }
};