class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        //horizontal distance
        int h=abs(fx-sx);
        //vertical distance
        int v=abs(sy-fy);
        return ((max(h,v)<=t && max(h,v)!=0) || (max(h,v)==0 && t!=1));
    }
};