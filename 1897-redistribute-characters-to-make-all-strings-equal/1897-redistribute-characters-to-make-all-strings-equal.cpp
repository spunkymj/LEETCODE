class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> c(26,0);
        for(auto s : words){
            for(auto ch : s){
                c[ch-'a']++;
            }
        }
        int n=words.size();
        for(int i=0 ; i<26 ; i++){
            if(c[i]%n!=0){
                return false;
            }
        }
        return true;
    }
};