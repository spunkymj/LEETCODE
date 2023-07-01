class Solution {
public:
    bool poss(vector<int>& cookies, int k,int target,int curr,int state){
        if(state==((1<<cookies.size())-1)){
            k--;
            return k>=0;
        }
        bool chk=false;
        for(int i=0 ; i<cookies.size() ; i++){
            if((state&(1<<i))==0){
                if(curr+cookies[i]<=target){
                    chk|=poss(cookies,k,target,curr+cookies[i],state|(1<<i));
                    if(chk){
                        return chk;
                    }
                }
                else if(cookies[i]<=target){
                    chk|=poss(cookies,k-1,target,cookies[i],state|(1<<i));
                    if(chk){
                        return chk;
                    }
                }
            }
        }
        return chk;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int l=1 ; 
        int r=accumulate(cookies.begin(),cookies.end(),0);
        int ans;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(poss(cookies,k,mid,0,0)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};