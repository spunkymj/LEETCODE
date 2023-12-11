class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        for(int i=0 ; i<n ; i++){
            int curr=arr[i];
            int cnt=0;
            while(i<n && arr[i]==curr){
                i++;
                cnt++;
            }
            i--;
            if(cnt*4>n){
                return curr;
            }
        }
        return arr[0];
    }
};