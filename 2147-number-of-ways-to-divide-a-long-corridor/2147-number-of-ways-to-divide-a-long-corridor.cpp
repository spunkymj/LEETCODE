class Solution {
public:
    const int mod=1e9+7;
    int numberOfWays(string c) {
        vector<long long> pos(0);
        for(int i=0 ; i<c.size() ; i++){
            if(c[i]=='S'){
                pos.push_back(i);
            }
        }
        if(pos.size()%2==1 || pos.size()<2){
            return 0;
        }
        long long ans=1;
        for(int i=1 ; i<(pos.size()-1) ; i+=2){
            ans*=(pos[i+1]-pos[i]);
            ans%=mod;
        }
        return ans;
    }
};