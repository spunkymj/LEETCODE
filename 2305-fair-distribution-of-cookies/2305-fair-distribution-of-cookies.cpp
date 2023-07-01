class Solution {
public:
    //We have k groups
    //For each cookie we have k options

    //Two optimizations :
    //1.If number of cookies left < number of empty partions,it's not a valid distribution
    //2.If we already have a partion with value > sum/k (avg) then it's not optimal to add new value(cookie) to it.

    int solve(vector<int>& cookies, int &k,vector<int> &dis,int idx,int zero,int &avg){
        if(idx==cookies.size()){
            return *max_element(dis.begin(),dis.end());
        }

        if(cookies.size()-idx < zero){
            return INT_MAX;
        }

        int ans=INT_MAX;
        for(int i=0 ; i<k ; i++){
            if(dis[i]>=avg){
                continue;
            }
            zero-=dis[i]==0 ? 1 : 0;
            dis[i]+=cookies[idx];
            ans=min(ans,solve(cookies,k,dis,idx+1,zero,avg));
            dis[i]-=cookies[idx];
            zero+=dis[i]==0 ? 1 : 0;
        }
        return ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dis(k,0);
        int avg=accumulate(cookies.begin(),cookies.end(),0)/k;
        return solve(cookies,k,dis,0,k,avg);
    }
};