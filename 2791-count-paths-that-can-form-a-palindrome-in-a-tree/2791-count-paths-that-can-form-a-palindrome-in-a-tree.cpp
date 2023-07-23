class Solution {
public:
    //Obtaining all masks from root to v 
    void dfs(vector<vector<pair<int,char>>> &adj,int u,int &mask,unordered_map<int,long long> &mask_count){
        mask_count[mask]++;
        for(auto nbr : adj[u]){
            int ch=nbr.second;
            mask=mask^(1<<(ch-'a'));
            dfs(adj,nbr.first,mask,mask_count);
            mask=mask^(1<<(ch-'a'));
        }
        return;
    }

    long long countPalindromePaths(vector<int>& par, string s) {
        int n=par.size();
        vector<vector<pair<int,char>>> adj(n);
        for(int i=1 ; i<n ; i++){
            adj[par[i]].push_back({i,s[i]});
        }
        unordered_map<int,long long> mask_count;
        int mask=0;
        dfs(adj,0,mask,mask_count);

        long long ans=0;
        for(auto mask : mask_count){
            int i=mask.first;
            long long m=mask.second;

            //odd length palindrome
            for(int j=0 ; j<26 ; j++){
                int other=(int)(i^(1<<j));
                if(mask_count.find(other)!=mask_count.end()){
                    ans+=m*mask_count[other];
                }
            }

            //even length palindrome
            ans+=m*(m-1);
        }

        return ans/2;
    }
};