class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int ptr=0;
        int n=words.size();
        vector<string> ans;
        while(ptr<n){
            int space=0;
            int wordsize=0;
            int start=ptr;
            while(ptr<n && wordsize+words[ptr].size()+space<=maxWidth){
                space++;
                wordsize+=words[ptr].size();
                ptr++;
            }
            //left extra space
            int rem=0;
            //extra space for evenly spaced
            int xtra=0;
            //leftover size
            int q=maxWidth-words[start].size()-1;
            if(space!=1){
                xtra=maxWidth-(wordsize+space-1);
                q=xtra/(space-1);
                rem=xtra%(space-1);
            }
            string insertspace=" ";
            for(int i=0 ; i<q ; i++){
                insertspace+=" ";
            }
            string small="";
            while(start<ptr){
                small+=words[start++];
                small+=insertspace;
                if(rem){
                    small+=" ";
                    rem--;
                }
                cout<<small<<" ";
            }
            while(small.size()>maxWidth){
                small.pop_back();
            }
            ans.push_back(small);
        }

        //Handling lastline
        string last=ans.back();
        vector<string> lastlinewords;
        string curr="";
        for(int i=0 ; i<maxWidth ; i++){
            if(last[i]==' '){
                if(curr!=""){
                    lastlinewords.push_back(curr);
                }
                curr="";
                continue;
            }
            curr+=last[i];
        }
        if(curr!=""){
            lastlinewords.push_back(curr);
        }
        string lastans="";
        for(int i=0 ; i<lastlinewords.size() ; i++){
            if(i!=0){
                lastans+=" ";
            }
            lastans+=lastlinewords[i];
        }
        int sz=lastans.size();
        for(int i=0 ; i<maxWidth-sz ; i++){
            lastans+=" ";
        }
        ans.back()=lastans;
        return ans;
    }
};