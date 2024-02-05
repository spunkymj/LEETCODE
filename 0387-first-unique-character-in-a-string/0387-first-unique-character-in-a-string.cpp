class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> scount(26);
        for (int i=0 ; i < s.size() ; i++){
            scount[s[i]-'a']+=1;
        }
        for(int i=0 ; i<s.size(); i++){
            if (scount[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};