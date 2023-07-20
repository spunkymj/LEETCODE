class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n=asteroids.size();
        for(int i=0 ; i<n ; i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()<abs(asteroids[i])){
                    st.pop();
                }
                bool chk=false;
                if(!st.empty() && (st.top()==abs(asteroids[i]))){
                    st.pop();
                    chk=true;
                }
                if(chk){
                    continue;
                }
                if(st.empty()){
                    ans.push_back(asteroids[i]);
                }
            }
        }
        stack<int> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }
};