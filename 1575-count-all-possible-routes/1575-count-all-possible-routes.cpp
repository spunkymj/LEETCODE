class Solution {
public:
    int mod=1e9+7;

    int countRoutes(vector<int>& l, int start, int finish, int fuel) {
        int n=l.size();
        vector<vector<int>> dp(n,vector<int>(fuel+1,0));
        dp[start][fuel]=1;
        for(int f=fuel ; f>=0 ; f--){
            for(int i=0 ; i<n ; i++){
                if(!dp[i][f] || abs(l[i]-l[finish])>f){
                    continue;
                }
                for(int j=0 ; j<n ; j++){
                    int d=abs(l[j]-l[i]);
                    if(i==j || (d>f)){
                        continue;
                    }
                    
                    dp[j][f-d]+=dp[i][f];
                    dp[j][f-d]%=mod;
                }
            }
        }

        int ans=0;
        for(int f=0 ; f<=fuel ; f++){
            ans+=dp[finish][f];
            ans=ans%mod;
        }

        return ans;
    }
};