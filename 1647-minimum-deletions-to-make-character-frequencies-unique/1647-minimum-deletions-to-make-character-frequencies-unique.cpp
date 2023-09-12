class Solution {
public:
    int minDeletions(string s) {
       vector<int> c(26,0);
       for(auto e:s){
           c[e-'a']++;
       } 
       unordered_map<int,int> mp;
       int ans=0;
       sort(c.begin(),c.end());
       for(int i=0 ; i<26 ; i++){
           if(c[i]==0){
               continue;
           }
           if(mp[c[i]]==0){
               mp[c[i]]++;
               continue;
           }
           else{
                int curr=c[i];
                while(mp[curr]!=0){
                    curr--;
                }
                if(curr!=0){
                    mp[curr]++;
                    ans+=c[i]-curr;
                }
                else{
                    ans+=c[i];
                }
           }
       }
       return ans;
    }
};