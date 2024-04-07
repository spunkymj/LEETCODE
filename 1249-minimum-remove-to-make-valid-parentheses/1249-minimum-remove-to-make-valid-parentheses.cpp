#define all(x) (x).begin(),(x).end()

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string ans="";
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='('){
                ans+=s[i];
                st.push(1);
            }
            else if(s[i]==')'){
                if(st.empty()){

                }
                else{
                    st.pop();
                    ans+=s[i];
                }
            }
            else{
                ans+=s[i];
            }
        }
        if(st.empty()){
            return ans;
        }

        string ans2="";
        for(int i=ans.size()-1 ; i>=0 ; i--){
            if(ans[i]=='('){
                if(st.size()){
                    st.pop();
                }
                else{
                    ans2+=ans[i];
                }
            }
            else{
                ans2+=ans[i];
            }
        }

        reverse(all(ans2));
        return ans2; 
    }
};