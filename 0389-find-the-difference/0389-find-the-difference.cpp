class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> c(26,0);
        for(auto e : t){
            c[e-'a']++;
        }
        for(auto e : s){
            c[e-'a']--;
        }
        for(int i=0 ; i<26 ; i++){
            if(c[i]==1){
                return 'a'+i;
            }
        }
        return 'a';
    }
};