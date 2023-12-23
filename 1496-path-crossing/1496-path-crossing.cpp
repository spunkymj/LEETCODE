class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        st.insert({0,0});
        int r=0;
        int c=0;
        for(int i=0 ; i<path.size() ; i++){
            if(path[i]=='N'){
                c++;
            }
            else if(path[i]=='S'){
                c--;
            }
            else if(path[i]=='E'){
                r++;
            }
            else{
                r--;
            }
            if(st.count({r,c})){
                return true;
            }
            st.insert({r,c});
        }
        return false;

    }
};