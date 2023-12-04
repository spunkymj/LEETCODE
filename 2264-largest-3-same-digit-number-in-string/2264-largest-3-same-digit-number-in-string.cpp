class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> s={"000","111","222","333","444","555","666","777","888","999"};
        for(int i=s.size()-1 ; i>=0 ; i--){
            for(int j=0 ; j<num.size()-2 ; j++ ){
                string str="";
                for(int k=j; k<j+3 ; k++){
                    str+=num[k];
                }
                if(str==s[i]){
                    return s[i];
                }
            }
        }
        return "";
    }
};