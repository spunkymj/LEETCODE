class Solution {
public:
    int minOperations(string s) {
        int ans1=0;
        int ans2=0;
        for(int i=0 ; i<s.size() ; i++){
            if(i&1){
                ans1+=(s[i]=='1');
                ans2+=(s[i]=='0');
            }
            else{
                ans2+=(s[i]=='1');
                ans1+=(s[i]=='0');
            }
        }
        return min(ans1,ans2);
    }
};