class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> win;
        map<int,int> lose;
        for(int i=0 ; i< matches.size() ; i++){
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto m : win){
            if(lose[m.first]==0){
                ans[0].push_back(m.first);
            }
        }
        for(auto m : lose){
            if(m.second==1){
                ans[1].push_back(m.first);
            }
        }
        return ans;
    }
};