class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> prev(m+1,0),curr(m+1,0);

        for(int j1=1 ; j1<=n ; j1++){
            for(int j2=1 ; j2<=m ; j2++){
                if(text1[j1-1]==text2[j2-1]){
                    curr[j2]=1+prev[j2-1];
                }
                else{
                    curr[j2]=max(prev[j2],curr[j2-1]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};