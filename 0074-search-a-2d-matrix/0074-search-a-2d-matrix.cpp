class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    {
        int n=matrix.size(),m=matrix[0].size();
        int l=0,h=(m*n)-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int x=matrix[mid/m][mid%m];
            if(x==target)
            {
                return 1;
            }
            if(x<target){
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return 0;
    }
    }
};