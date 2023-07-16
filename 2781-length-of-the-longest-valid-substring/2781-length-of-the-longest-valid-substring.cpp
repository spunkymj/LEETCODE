class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.size();
        int ret = 0;
        int mx = 0;
        unordered_map<string,int> mp;
        for(auto &f : forbidden){
            mp[f]++;
        }
        for (int i=0; i<n; i++) {
            for (int j=i; j>=max(i-9,0); j--)
                if (mp.count(word.substr(j, i - j + 1)))
                    mx = max(mx, j + 1);
            ret = max(ret, i - mx + 1);
        }
        return ret;
    }
};