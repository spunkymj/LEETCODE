class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26,-1);
        vector<int> last(26,-1);
        int n=s.size();
        for(int i=0;i<n ; i++){
            if(first[s[i]-'a']==-1){
                first[s[i]-'a']=i;
            }
            last[s[i]-'a']=i;
        }
        int ans=0;
        for(int j=0 ; j<26 ; j++){
            if(first[j]!=-1 && last[j]!=-1){
                set<char> st;
                for(int i=first[j]+1 ; i<last[j] ; i++){
                    st.insert(s[i]);
                }
                ans+=st.size();
            }
        }
        return ans;
    }
};