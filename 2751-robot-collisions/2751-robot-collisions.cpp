class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        int n=p.size();
        vector<int> order(n,0);
        iota(order.begin(),order.end(),0);
        sort(order.begin(),order.end(),[&](int x,int y){
            return p[x]<p[y];
        });
        stack<int> st;
        for(int i : order){
            //chk checks whether to add current i to stack or not
            bool chk=true;
            while(!st.empty() && d[i]=='L' && d[st.top()]=='R'){
                int x=st.top();
                st.pop();
                if(h[i]>h[x]){
                    h[i]--;
                }
                else if(h[x]>h[i]){
                    h[x]--;
                    st.push(x);
                    chk=false;
                    break;
                }
                else{
                    chk=false;
                    break;
                }
            }
            if(chk){
                st.push(i);
            }
        }


        vector<int> mark(n,0);
        while(!st.empty()){
            mark[st.top()]=1;
            st.pop();
        }
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            if(mark[i]){
                ans.push_back(h[i]);
            }
        }
        return ans;
    }
};