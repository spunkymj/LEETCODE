bool comp(string &s1,string &s2){
    return s1.size()<s2.size();
}
class Solution {
public:
    bool compare(string &s1,string &s2){
        if(s1.size()==s2.size()+1){
            int i=0,j=0;
            while(i<s1.size() && j<s2.size()){
                if(s1[i]==s2[j]){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
            return ((i==s1.size()||i==s1.size()-1) && j==s2.size());
        }
        return false;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int> dp(n,1);
        int maxi=0;
        for(int idx=0 ; idx<n ; idx++){
            for(int prev=0 ; prev<idx; prev++){
                if(compare(words[idx],words[prev]) && 1+dp[prev]>dp[idx]){
                    dp[idx]=1+dp[prev];
                }
            }
            if(dp[idx]>maxi){
                maxi=dp[idx];
            }
        }
        return maxi;
    }
};