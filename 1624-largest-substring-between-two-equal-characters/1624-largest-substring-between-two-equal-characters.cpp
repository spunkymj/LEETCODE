class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<vector<int>> c(26);
        for(int i=0 ; i<s.size() ; i++){
            c[(s[i]-'a')].push_back(i);
        }
        int ans=-1;
        for(int i=0 ; i<26 ; i++){
            if((c[i].size())<=1){
                continue;
            }
            ans=max(ans,(c[i][c[i].size()-1]-c[i][0]-1));
        }
        return ans;
    }
};