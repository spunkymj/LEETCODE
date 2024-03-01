class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        for(auto e : s){
            if(e=='1'){
                ones++;
            }
        }
        ones--;
        s[s.size()-1]='1';
        for(int i=0 ; i<ones ; i++){
            s[i]='1';
        }
        for(int i=ones ; i<s.size()-1 ; i++){
            s[i]='0';
        }
        return s;
    }
};