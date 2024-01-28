class Solution {
public:
    
    int findtargetSum(vector<int>arr, int k){
        int count=0;
        unordered_map<int,int>mp;
        int sum=0;
        mp[sum]=1;
        
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            if(mp.find(sum-k)!=mp.end()){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int count=0;
        
        for(int k=0; k<m; k++){
            vector<int>arr(n,0);
            
            for(int i=k; i<m; i++){
                for(int j=0; j<n; j++){
                    arr[j]=arr[j]+matrix[i][j];
                }
                count+=findtargetSum(arr, target);
            }
        }
        
        return count;
    }
};