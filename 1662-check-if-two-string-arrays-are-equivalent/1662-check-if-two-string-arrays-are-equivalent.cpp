class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s="";
        string r="";
        for(string i : word1){
            for(char c : i ){
                s+=c;
            }
        }
        for(string i : word2){
            for(char c : i ){
                r+=c;
            }
        }
        if(r==s){
            return true;
        }
        return false;
    }
};