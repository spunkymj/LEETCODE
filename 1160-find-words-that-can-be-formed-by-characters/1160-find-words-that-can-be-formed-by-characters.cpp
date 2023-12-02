class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        vector<int> c(26,0);
        for(auto e : chars){
            c[e-'a']++;
        }
        for(auto s : words){
            vector<int> curr(26,0);
            for(auto e : s){
                curr[e-'a']++;
            }
            bool chk=true;
            for(int i=0 ; i<26 ; i++){
                if(curr[i]>c[i]){
                    chk=false;
                    break;
                }
            }
            if(chk){
                ans+=s.size();
            }
        }
        return ans;
    }
};