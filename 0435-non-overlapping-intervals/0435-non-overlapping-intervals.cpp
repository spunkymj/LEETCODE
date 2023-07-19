class Solution {
public:
    bool static cmp(vector<int> &v1,vector<int> &v2){
        return v1[1]<v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        int ans=0;
        int end=INT_MIN;
        for(int i=0; i<n ; i++){
            if(intervals[i][0]>=end){
                end=intervals[i][1];
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};