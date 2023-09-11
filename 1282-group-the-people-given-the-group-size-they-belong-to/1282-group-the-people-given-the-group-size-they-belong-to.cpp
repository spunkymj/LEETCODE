class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>> seg(n+1);
        for(int i=0 ; i<n;i++){
            seg[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(int sz=1 ; sz<=n ; sz++){
            vector<int> temp;
            for(auto e : seg[sz]){
                temp.push_back(e);
                if(temp.size()==sz){
                    ans.push_back(temp);
                    temp.resize(0);
                }
            }
        }
        return ans;
    }
};