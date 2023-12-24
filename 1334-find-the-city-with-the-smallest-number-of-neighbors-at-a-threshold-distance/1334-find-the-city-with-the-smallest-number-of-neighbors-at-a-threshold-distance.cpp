class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<long long>> dis(n,vector<long long> (n,1e12));
        for(auto &v : edges){
            dis[v[0]][v[1]]=min((long long)v[2],dis[v[0]][v[1]]);
            dis[v[1]][v[0]]=min((long long)v[2],dis[v[1]][v[0]]);
        }
        for(int i=0 ; i<n ; i++){
            dis[i][i]=0;
        }
        for(int k=0 ; k<n ; k++){
            for(int i=0 ; i<n  ; i++){
                for(int j=0 ; j<n ; j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        long long mini=1e9;
        int ans=0;
        for(int i=0 ; i<n ; i++){
            int curr=0;
            for(int j=0 ; j<n ; j++){
                if(i==j){
                    continue;
                }
                if(dis[i][j]<=th){
                    curr++;
                }
            }
            if(curr<=mini){
                ans=i;
                mini=curr;
            }
        }
        
        return ans;
    }
};