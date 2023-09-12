class Solution {
public:
    int minDeletions(string s) {
        vector<int> c(26,0);
        for(auto e:s){
            c[e-'a']++;
        } 
        unordered_map<int,int> mp;
        int st=0;
        for(int i=0  ;i<26 ; i++){
            mp[c[i]]++;
            st=max(st,c[i]);
        }
        
        priority_queue<pair<int,int>> pq;

        int ans=0;
        for(int val=st ; val>=1 ; val--){
            if(mp[val]==0){
                if(!pq.empty()){
                    int maxi=pq.top().first;
                    int cnt=pq.top().second;
                    pq.pop();
                    ans+=maxi-val;
                    cnt--;
                    if(cnt>0){
                        pq.push({maxi,cnt});
                    }
                }
            }
            else if(mp[val]>1){
                pq.push({val,mp[val]-1});
            }
        }
        while(!pq.empty()){
            int maxi=pq.top().first;
            int cnt=pq.top().second;
            pq.pop();
            ans+=maxi;
            cnt--;
            if(cnt>0){
                pq.push({maxi,cnt});
            }
        }
        
        return ans;
    }
};