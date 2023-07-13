class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>> adj(V);
        for(auto v : prerequisites){
            adj[v[1]].push_back(v[0]);
        }
	    vector<int> ind(V,0);
	    for(int i=0 ; i<V ; i++){
	        for(auto a  : adj[i]){
	            ind[a]++;
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

	    return ans.size()==V;
    }
};