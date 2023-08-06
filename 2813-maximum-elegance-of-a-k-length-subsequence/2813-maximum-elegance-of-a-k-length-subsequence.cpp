class Solution {
public:
    bool static cmp(vector<int> &v1,vector<int> &v2){
        return v1[0]>v2[0];
    }
    
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n=items.size();
        priority_queue<pair<long long,long long>> pq;
        unordered_map<long long,long long> mp;
        sort(items.begin(),items.end(),cmp);
        long long ans=0;
        for(int i=0 ; i<k ; i++){
            ans+=items[i][0];
            pq.push({-items[i][0],i});
            mp[items[i][1]]++;
        }
        long long res=ans+(long long)mp.size()*(long long)mp.size();
        int ptr=k;
        while(ptr<n && !pq.empty()){
            if(mp[items[ptr][1]]>0){
                ptr++;
                continue;
            }
            int curr=pq.top().second;
            pq.pop();
            if(mp[items[curr][1]]==1){
                continue;
            }
            ans+=items[ptr][0]-items[curr][0];
            --mp[items[curr][1]];
            ++mp[items[ptr][1]];
            res=max(res,ans+(long long)mp.size()*(long long)mp.size());
        }
        return res;
    }
};