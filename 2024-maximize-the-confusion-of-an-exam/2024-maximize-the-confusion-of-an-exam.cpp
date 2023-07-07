class Solution {
public:
    int poss(string &s, int &k,int mid){
        int t=0;
        int f=0;
        for(int i=0 ; i<mid ; i++){
            if(s[i]=='F'){
                f++;
            }
            else{
                t++;
            }
        }
        if(min(t,f)<=k){
            return true;
        }

        for(int i=mid ; i<s.size() ; i++){
            if(s[i-mid]=='F'){
                f--;
            }
            else{
                t--;
            }
            if(s[i]=='F'){
                f++;
            }
            else{
                t++;
            }
            if(min(t,f)<=k){
                return true;
            }
        }
        return false;
    }

    int maxConsecutiveAnswers(string s, int k) {
        int l=1;
        int r=s.size();
        int ans=0;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(poss(s,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};