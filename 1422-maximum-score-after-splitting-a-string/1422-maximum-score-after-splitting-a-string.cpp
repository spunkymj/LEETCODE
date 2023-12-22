class Solution {
public:
    int maxScore(string s) {
        vector<int> ones(s.size(),0);
        for(int i=0 ; i<s.size()  ; i++){
            ones[i]+=(s[i]=='1');
            if(i>0){
                ones[i]+=ones[i-1];
            }
        }
        int ans=0;
        for(int i=0 ; i<s.size()-1 ; i++){
            ans=max(ans,(i+1-ones[i])+(ones[s.size()-1]-ones[i]));
        }
        return ans;
    }
};