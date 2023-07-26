class Solution {
public:
    double gettime(vector<int>& dist,int s){
        int n=dist.size();
        double t=0;
        for(int i=0 ; i<n-1 ; i++){
            t+=(dist[i]+s-1)/s;
        }
        t+=((double)dist[n-1]/(double)s);
        return t;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1;
        int r=1e9;
        int ans=-1;
        while(l<=r){
            int mid=l+((r-l)/2);
            double time=gettime(dist,mid);
            if(time<=hour){
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