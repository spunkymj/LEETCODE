class Solution {
public:
    bool static cmp(vector<int> &v1,vector<int> &v2){
        return v1[0]<v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int st=INT_MAX;
        int end=0;
        int n=intervals.size();
        for(int i=0 ; i<n-1 ; i++){
            st=min(intervals[i][0],st);
            end=max(end,intervals[i][1]);
            if(end<intervals[i+1][0]){
                ans.push_back({st,end});
                st=INT_MAX;
                end=0;
            }
        }
        st=min(st,intervals[n-1][0]);
        end=max(end,intervals[n-1][1]);
        ans.push_back({st,end});
        return ans;
    }
};