class Solution {
public:
    int pivotInteger(int n) {
        int s=0;
        for(int i=1 ; i<=n ; i++){
            s+=i;
            if((n*(n+1)/2-(i-1)*(i)/2)==s){
                return i;
            }
        }
        return -1;
    }
};