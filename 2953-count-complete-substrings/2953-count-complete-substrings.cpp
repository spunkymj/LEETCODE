class Solution {
public:
    bool valid(vector<int> &c,int k){
        bool chk=true;
        for(int l=0 ; l<26 ; l++){
            if((c[l]!=0 && c[l]!=k)){
                chk=false;
            }
        }
        return chk;
    } 

    int countCompleteSubstrings(string word, int k) {
        int n=word.size();
        int ans=0;
        for(int len=1 ; len<=26 ; len++){
            int sz=k*len;
            if(sz>n){
                break;
            }
            vector<int> c(26,0);
            int pos=-1;
            for(int j=0 ; j<sz ; j++){
                c[word[j]-'a']++;
                if(j>0 && abs((word[j]-'a')-(word[j-1]-'a'))>2) {
                    pos=j-1;
                }
            }
            if(pos<0 && valid(c,k)){
                ans++;
            }
            for(int j=sz ; j<n ; j++){
                c[word[j-sz]-'a']--;
                c[word[j]-'a']++;
                if(sz>1 && abs((word[j]-'a')-(word[j-1]-'a'))>2) {
                    pos=j-1;
                }
                if(pos<=(j-sz) && valid(c,k)){
                    ans++;
                }
            }
        }
        return  ans;
    }
};