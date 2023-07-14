class Solution {
public:
    int upper_bound(vector<vector<int>> &events,int st){
        if(events[events.size()-1][0]<=st){
            return events.size();
        }
        int l=0;
        int r=events.size()-1;
        int ret=-1;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(st<events[mid][0]){
                ret=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ret;
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        vector<int> prefix(events.size()+1,0);
        for(int i=events.size()-1 ; i>=0 ; i--){
            prefix[i]=max(prefix[i+1],events[i][2]);
        }
        int ans=0;
        for(int i=0 ; i<events.size() ; i++){
            auto it=upper_bound(events,events[i][1]);
            int curr=events[i][2];
            if(it!=events.size()){
                curr+=prefix[it];
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};