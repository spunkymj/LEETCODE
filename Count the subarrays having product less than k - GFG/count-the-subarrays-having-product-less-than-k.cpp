//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long p=1;
        int i=0;  
        int j=0;
        int ans=0;
        while(i<=j && j<n){
            while(j<n && p*a[j]<k){
                p=p*a[j];
                j++;
            }
            if(p%a[i]==0){
                ans+=j-i;
                p=p/a[i];
                i++;
            }
            else{
                i++;
                j++;
            }
        }
        while(i<j){
            if(p<k){
                ans+=j-i;
            }
            p=p/a[i];
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends