class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> mpt;
        for(char e : t){
            mpt[e]++;
        }
        int start=0;
        unordered_map<int,int> mps;
        int start_index=-1;
        int mini=100001;
        int count=0;
        for(int i=0 ; i<s.size() ; i++){
            mps[s[i]]++;
            if(mps[s[i]]<=mpt[s[i]]){
                count++;
            }
            if(count==t.size()){
                while(mpt[s[start]]==0 || mps[s[start]]>mpt[s[start]]){
                    if(mps[s[start]]>mpt[s[start]]){
                        mps[s[start]]--;
                    }
                    start++;
                }
                int len=i-start+1;
                if(len<mini){
                    start_index=start;
                    mini=len;
                }
            }
        }
        if(start_index==-1){
            return "";
        }
        return s.substr(start_index, mini);
    }
};