class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        int t=0;
        int mm=m.size();
        vector<long long> last(n,0);
        vector<long long> used(n,0);
        sort(m.begin(),m.end(),[&](vector<int> v1,vector<int> v2){
            if(v1[0]==v2[0]){
                return v1[1]<v2[1];
            }
            return v1[0]<v2[0];
        });
        int itr=0;
        while(itr<mm){
            bool got=false;
            for(int i=0 ; i<n ; i++){
                if(m[itr][0]>=last[i]){
                    last[i]=m[itr][1];
                    used[i]++;
                    itr++;
                    got=true;
                    break;
                }
            }
            if(itr>=mm){
                break;
            }
            if(got){
                continue;
            }
            long long mini=1e18;
            int id=-1;
            for(int i=0 ; i<n ; i++){
                if(last[i]<mini){
                    mini=last[i];
                    id=i;
                }
            }
            last[id]+=(long long)(m[itr][1]-m[itr][0]);
            used[id]++;
            itr++;
        }
        long long ans=0;
        for(auto e : used){
            ans=max(ans,e);
        }
        for(int i=0 ; i<n ; i++){
            if(used[i]==ans){
                return i;
            }
        }
        return 0;
    }
};