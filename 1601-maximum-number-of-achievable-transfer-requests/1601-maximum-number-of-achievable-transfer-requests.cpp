class Solution {
public:
    int ans;
    void solve(vector<vector<int>>& r,vector<int> &indegree,int idx,int taken){
        if(idx==r.size()){
            bool chk=true;
            for(auto e : indegree){
                if(e!=0){
                    chk=false;
                    break;
                }
            }
            if(chk){
                ans=max(ans,taken);
            }
            return;
        }

        indegree[r[idx][1]]++;
        indegree[r[idx][0]]--;
        solve(r,indegree,idx+1,taken+1);
        indegree[r[idx][1]]--;
        indegree[r[idx][0]]++;

        solve(r,indegree,idx+1,taken);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        ans=0;
        vector<int> indegree(n,0);
        solve(requests,indegree,0,0);
        return ans;
    }
};