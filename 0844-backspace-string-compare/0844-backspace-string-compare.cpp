class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        for(auto e : s){
            if(e=='#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }
            else{
                st1.push(e);
            }
        }

        stack<char> st2;
        for(auto e : t){
            if(e=='#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }
            else{
                st2.push(e);
            }
        }

        string a="";
        while(!st1.empty()){
            a+=st1.top();
            st1.pop();
        }
        string b="";
        while(!st2.empty()){
            b+=st2.top();
            st2.pop();
        }

        return a==b;
    }
};