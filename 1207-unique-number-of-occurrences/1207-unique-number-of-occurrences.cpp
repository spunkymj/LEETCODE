class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        for(int i=0  ; i<n ; i++){
            int count=0;
            int curr=arr[i];
            while(i<n && arr[i]==curr){
                i++;
                count++;
            }
            i--;
            cout<<count<<endl;
            if(mp[count]){
                return false;
            }
            mp[count]=1;
        }
        return true;
    }
};