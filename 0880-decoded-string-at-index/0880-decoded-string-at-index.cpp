class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string str="";
        unordered_map<char,int> mp;
        for(int i=0 ; i<26 ; i++){
            mp['a'+i]=1;
        }
        long long n=s.size();
        long long curr=0;
        for(int i=0 ; i<n ; i++){
            if(mp[s[i]]){
                curr++;
            }
            else{
                curr+=(curr)*(s[i]-'0'-1);
            }
        }
        for(int i=n-1 ;  i>=0 ; i--){
            if(mp[s[i]]){
                if(k==0 || k==curr){
                    string ans="";
                    ans+=s[i];
                    return ans;
                }
                curr--;
            }
            else{
                curr/=(s[i]-'0');
                k%=curr;
            }
        }
        return "mj";
    }
};