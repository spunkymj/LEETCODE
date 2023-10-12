/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int n=m.length();
        int l=0;
        int r=n-1;
        int peak=0;
        while(l<=r){
            int mid=(l+r)/2;
            int val1=m.get(mid);
            int val2=m.get(mid+1);
            if(val1<val2){
                l=mid+1;
            }
            else{
                peak=mid;
                r=mid-1;
            }
        }

        int l1=0;
        int r1=peak;
        while(l1<=r1){
            int mid=(l1+r1)/2;
            int val=m.get(mid);
            if(val<target){
                l1=mid+1;
            }
            else if(val>target){
                r1=mid-1;
            }
            else{
                return mid;
            }
        }

        int l2=peak;
        int r2=n-1;
        while(l2<=r2){
            int mid=(l2+r2)/2;
            int val=m.get(mid);
            if(val<target){
                r2=mid-1;
            }
            else if(val>target){
                l2=mid+1;
            }
            else{
                return mid;
            }
        }

        return -1;
    }
};