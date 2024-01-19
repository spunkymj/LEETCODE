class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n,0);
        vector<int> curr(n,0);
        for(int i=0 ; i<n ; i++){
            prev[i]=matrix[0][i];
        }
        for(int i=1 ; i< n ; i++){
            for(int j=0 ; j<n ; j++){
                int case1=matrix[i][j]+prev[j];
                int case2=matrix[i][j];
                if(j>0){
                    case2+=prev[j-1];
                }
                else{
                    case2+=1000001;
                }
                int case3=matrix[i][j];
                if(j<n-1){
                    case3+=prev[j+1];
                }
                else{
                    case3+=1000001;
                }
                curr[j]=min(case1,min(case2,case3));
            }
            prev=curr;
        }
        int mini=1000001;
        for(int i=0 ; i<n ; i++){
            mini=min(mini,prev[i]);
        }
        return mini;
    }
};