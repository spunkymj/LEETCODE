class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        map<int,int> mp;
        for(int i=0 ; i<points.size() ; i++){
            mp[points[i][0]]++;
        }
        bool chk=false;
        int prev;
        int ans=0;
        for(auto m : mp){
            if(!chk){
                chk=true;
                prev=m.first;
                continue;
            }
            ans=max(ans,m.first-prev);
            prev=m.first;
        }
        return ans;
    }
};