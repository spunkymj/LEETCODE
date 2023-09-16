class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,  greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        vector<vector<int>> dis(n,vector<int> (m,INT_MAX));
        dis[0][0]=0;
        vector<int> dir={-1,0,1,0,-1};
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int d=pq.top().first;
            pq.pop();

            if(r==n-1 && c==m-1){
                return d;
            }


            for(int i=0  ;i<4 ; i++){
                int nr=r+dir[i];
                int nc=c+dir[i+1];
                if(nc>=0 && nr>=0 && nr<n && nc<m){
                    int new_eff=max(abs(heights[nr][nc]-heights[r][c]),d);
                    if(new_eff<dis[nr][nc]){
                        dis[nr][nc]=new_eff;
                        pq.push({dis[nr][nc],{nr,nc}});
                    }
                }
            }

        }
        return 0;
    }
};