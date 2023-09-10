class Solution {
public:
    //Z-Algorithm
    
    vector<int> calculateZ(string &s){
        vector<int> z(s.size(),0);
        int l=0;
        int r=0;
        for(int k=1 ; k<s.size() ; k++){
            if(k>r){
                l=r=k;
                while(r<s.size() && s[r]==s[r-l]){
                    r++;
                }
                z[k]=r-l;
                r--;
            }
            else{
                int k1=k-l;
                if(z[k1]<r-k+1){
                    z[k]=z[k1];
                }
                else{
                    l=k;
                    while(r<s.size() && s[r]==s[r-l]){
                        r++;
                    }
                    z[k]=r-l;
                    r--;
                }
            }
        }
        return z;
    }

    int strStr(string haystack, string needle) {
        string helper=needle;
        helper+='$';
        helper+=haystack;
 
        vector<int> z=calculateZ(helper);
        for(int i=0 ; i<z.size() ; i++){
            if(z[i]==needle.size()){
                return i-needle.size()-1;
            }
        }
        return -1;
    }
};