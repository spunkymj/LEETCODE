class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> seg(m+1+n);
        for(int i=0 ; i<n ; i++){
            seg[group[i]+1].push_back(i);
        }
        int ptr=m+1;
        for(auto e : seg[0]){
            group[e]=ptr-1;
            seg[ptr].push_back(e);
            ptr++;
        }
        seg[0]={};

        vector<set<int>> adj_grp(m+1+n);
        vector<set<int>> adj_item(n+1);
        for(int i=0 ; i<beforeItems.size() ; i++){
            for(auto e : beforeItems[i]){
                if(group[e]!=group[i]){
                    adj_grp[group[e]+1].insert(group[i]+1);
                }
                else{
                    adj_item[e].insert(i);
                }
            }
        }

        vector<int> indegree_grp(m+1+n,0);
        for(int i=1 ; i<=m+n ; i++){
            for(auto e : adj_grp[i]){
                indegree_grp[e]++;
            }
        }

        queue<int> q;
        for(int i=1 ; i<=m+n ; i++){
            if(indegree_grp[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            unordered_map<int,int> indegree_item;
            for(auto item : seg[curr]){
                for(auto e : adj_item[item]){
                    indegree_item[e]++;
                }
            }

            queue<int> p;
            for(auto item  : seg[curr]){
                if(indegree_item[item]==0){
                    p.push(item);
                }
            }

            while(!p.empty()){
                int curr_item=p.front();
                p.pop();
                ans.push_back(curr_item);
                for(auto e : adj_item[curr_item]){
                    indegree_item[e]--;
                    if(indegree_item[e]==0){
                        p.push(e);
                    }
                }
            }

            for(auto e : adj_grp[curr]){
                indegree_grp[e]--;
                if(indegree_grp[e]==0){
                    q.push(e);
                }
            }
        }

        if(ans.size()<n){
            return {};
        }
        return ans;
    }
};