class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        int sz=n;
        while(i<j){
            char c=s[i];
            if(s[j]!=c){
                break;
            }
            while(i<=j && s[i]==c){
                sz--;
                i++;
            }
            while(j>i && s[j]==c){
                sz--;
                j--;
            }
        }
        return sz;
    }
};