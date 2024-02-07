class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }
        vector<pair<int,char>> v;
        for(auto m : mp){
            v.push_back({m.second,m.first});
        }
        sort(v.begin(),v.end());
        string ans="";
        for(int i=v.size()-1 ; i>=0 ;  i--){
            while(v[i].first--){
                ans+=v[i].second;
            }
        }
        return ans;
    }
};