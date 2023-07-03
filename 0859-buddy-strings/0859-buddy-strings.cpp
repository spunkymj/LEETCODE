class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        vector<int> c1(26,0),c2(26,0);
        for(auto &e : s){
            c1[e-'a']++;
        }
        for(auto &e : goal){
            c2[e-'a']++;
        }
 
        for(int i=0; i<26 ; i++){
            if(c1[i]!=c2[i]){
                return false;
            }
        }
        
        int count=0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]!=goal[i]){
                count++;
            }
        }
        
        if(count!=0 && count!=2){
            return false;
        }
        
        if(count==2){
            return true;
        }
        if(count==0){
            for(int i=0 ; i<26 ; i++){
                if(c1[i]>1){
                    return true;
                }
            }
        }
        
        return false;
    }
};