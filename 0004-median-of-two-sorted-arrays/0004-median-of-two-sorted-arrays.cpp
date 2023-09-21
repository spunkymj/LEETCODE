class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<double> arr(n+m);
        int i=0;
        int j=0;
        int k=0;
        while (i<n && j<m){
            if (nums1[i]>nums2[j]){
                arr[k++]=nums2[j++];
            }
            else if(nums1[i]<nums2[j]){
                arr[k++]=nums1[i++];
            }
            else{
                arr[k++]=nums2[j++];
            }
        }
        if (i==n){
            while(j<m){
                arr[k++]=nums2[j++];
            }
        }
        if (j==m){
            while(i<n){
                arr[k++]=nums1[i++];
            }
        }
        if ((n+m)%2==0){
            int mid=(n+m)/2;
            return ((arr[mid]+arr[mid-1])/2);
        }
        else{
            int mid=(n+m)/2;
            return (arr[mid]);
        }
    }
};