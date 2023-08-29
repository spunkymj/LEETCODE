class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        long long n=receiver.size();
        long long log=35;
        vector<vector<long long>> parent(log,vector<long long>(n,-1));
        vector<vector<long long>> pathsum(log,vector<long long>(n,-1));
        for(int i=0 ; i<n ; i++){
            parent[0][i]=pathsum[0][i]=receiver[i];
        }
        for (int l = 1; l < log; l++) {
            for (int v = 0; v < n; v++) {
                parent[l][v] = parent[l - 1][parent[l - 1][v]];
                pathsum[l][v] = pathsum[l-1][v]+pathsum[l - 1][parent[l - 1][v]];
            }
        }
        long long ans=0;
        for(int i=0 ; i<n ; i++){
            long long curr=i;
            long long curr_sum=i;
            for(long long l=0 ; l<log ; l++){
                if((k&((((long long)1)<<l)))!=0){
                    curr_sum+=pathsum[l][curr];
                    curr=parent[l][curr];
                }
            }
            ans=max(ans,curr_sum);
        }
        return ans;
    }
};