class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(string s : tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                long long op2=st.top();
                st.pop();
                long long op1=st.top();
                st.pop();
                long long ans=0;
                if(s=="+"){
                    st.push(op1+op2);
                }
                else if(s=="-"){
                    st.push(op1-op2);
                }
                else if(s=="*"){
                    st.push(op1*op2);
                }
                else if(s=="/"){
                    st.push(op1/op2);
                }
            }
            else{
                long long temp=0;
                int j=1;
                for(int i=s.size()-1 ; i>=0 ; i--){
                    if(i==0){
                        if(s[0]=='-'){
                            temp=(-1)*temp;
                            break;
                        }
                    }
                    temp+=j*(s[i]-'0');
                    j*=10;
                }
                st.push(temp);
            }
        }
        return (int)st.top();
    }
};