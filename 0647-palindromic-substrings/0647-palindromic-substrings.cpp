class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            string curr="";
            for(int j=i ; j<n ; j++){
                curr+=s[j];
                string rev=curr;
                reverse(rev.begin(),rev.end());
                if(curr==rev){
                    ans++;
                }
            }
        }
        return ans;
    }
};