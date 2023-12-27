class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0;
        int mincost=0;
        int j=-1;
        while(i<colors.size()){
            int maxi=0;
            int c=0;
            while(i<colors.size()-1 && colors[i]==colors[i+1]){
                maxi=max(maxi,neededTime[i]);
                maxi=max(maxi,neededTime[i+1]);
                mincost+=neededTime[i];
                i++;
                c++;
            }
            if (c>0){
                mincost+=neededTime[i];
                mincost-=maxi;
            }
            i++;
        }
        return mincost;
    }
};