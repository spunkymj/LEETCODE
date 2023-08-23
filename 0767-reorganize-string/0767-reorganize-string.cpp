class Solution {
public:
    string reorganizeString(string s) {
        vector<pair<int,char>> c(26);
        for(int i=0 ; i<26; i++){
            c[i].second='a'+i;
        }
        for(int i=0 ; i<s.size(); i++){
            c[s[i]-'a'].first++;
        }
        sort(c.rbegin(),c.rend());
        string ans;
        for(int i=0 ; i<s.size() ; i++){
            ans+='.';
        }
        int ptr=0;
        for(pair<int,char> &p : c){
            char ch=p.second;
            int cnt=p.first;
            if(cnt>(s.size()+1)/2){
                return "";
            }
            while(cnt && ptr<s.size()){
                ans[ptr]=ch;
                ptr+=2;
                cnt--;
            }
            if(ptr>=s.size()){
                ptr=1;
            }
            while(cnt){
                ans[ptr]=ch;
                ptr+=2;
                cnt--;
            }
        }
        return ans;
    }
};