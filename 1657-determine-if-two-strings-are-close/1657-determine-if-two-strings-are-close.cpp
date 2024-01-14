class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26,0),v2(26,0),v3(26,0),v4(26,0);
        for(char c:word1)
            v1[c-'a']++,v3[c-'a'] = 1;
    
        for(char c:word2)
            v2[c-'a']++,v4[c-'a'] = 1;
        
        sort(begin(v1),end(v1));
        sort(begin(v2),end(v2));
        return v1==v2 && v3==v4;
    }
};