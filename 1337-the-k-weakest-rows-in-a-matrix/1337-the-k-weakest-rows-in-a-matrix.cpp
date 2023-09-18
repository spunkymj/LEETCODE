class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> ans;
        for(int i=0 ; i<mat.size() ; i++){
            int curr=0;
            for(int j=0 ; j<mat[0].size() ; j++){
                curr+=mat[i][j]&1;
            }
            ans.push_back({curr,i});
        }
        sort(ans.begin(),ans.end());
        vector<int> rs;
        for(int i=0 ; i<k ; i++){
            rs.push_back(ans[i].second);
        }
        return rs;
    }
};