class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=1 ; i<s.size() ; i++){
            if(s.size()%i==0){
                string str="";
                for(int j=0 ; j<i ; j++){
                    str+=s[j];
                }
                cout<<str<<endl;
                bool chk=true;
                for(int j=i ; j<s.size() ; j+=i){
                    string temp="";
                    for(int k=j ; k<j+i ; k++){
                        temp+=s[k];
                    }
                    cout<<temp<<" ";
                    if(temp!=str){
                        chk=false;
                        break;
                    }
                }
                if(chk){
                    return chk;
                }
            }
        }
        return false;
    }
};