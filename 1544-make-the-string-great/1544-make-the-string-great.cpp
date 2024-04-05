class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i=s.size()-1 ; i>=0 ; i--){
            if(!st.empty() && abs(s[i]-st.top())==32){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};