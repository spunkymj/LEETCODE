class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& c) {
        vector<long long> ans(5,0);
        unordered_map<long long,long long> mp;
        unordered_map<long long,long long> mpp;
        for(int i=0 ; i<c.size() ; i++){
            long long x=c[i][0];
            long long y=c[i][1];
            mp[x*n+y]=1;
        }
        vector<long long> dir1={-1,-1,0};
        vector<long long> dir2={0,-1,-1};
        for(int i=0 ; i<c.size() ; i++){
            long long x=c[i][0];
            long long y=c[i][1];
            mpp[x*n+y]+=1;
            for(int r=0 ; r<3 ; r++){
                long long nr=x+dir1[r];
                long long nc=y+dir2[r];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    mpp[nr*n+nc]+=(mp[x*n+y]);
                }
            }
        }
        for(auto &[x,y] : mpp){
            long long r=x/n;
            long long c=x%n;
            if(r<=m-2 && c<=n-2){
                ans[y]++;
            }
        }
        long long sum=0;
        for(auto &ele : ans){
            sum+=ele;
        }
        ans[0]+=((long long)(n-1)*(long long)(m-1))-sum;
        return ans;
    }
};