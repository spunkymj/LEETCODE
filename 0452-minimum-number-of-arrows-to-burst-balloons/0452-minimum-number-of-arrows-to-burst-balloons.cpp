bool cmp(vector<int> &a , vector<int> &b){
    return a[0]<b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;
        int n=points.size();
        sort(points.begin(),points.end(),cmp);
        int start=points[n-1][0];
        for(int i=n-2 ; i>=0 ; i--){
            if(points[i][1]>=start){            
                continue;
            }
            else{
                ans++;
                start=points[i][0];
            }
        }
        return ans;
    }
};