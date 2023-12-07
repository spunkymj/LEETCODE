class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int pos=-1;
        for(int i=num.size()-1 ; i>=0 ; i--){
            if((num[i]-'0')&1){
                pos=i;
                break;
            }
        }
        for(int i=0 ; i<=pos ; i++){
            ans+=num[i];
        }
        return ans;
    }
};