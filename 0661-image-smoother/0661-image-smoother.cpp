class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0 ; i<n; i++){
            for(int j=0 ; j<m ; j++){
                long long sum=0;
                int tot=0;
                for(int r=-1 ; r<=1 ; r++){
                    for(int c=-1 ; c<=1 ; c++){
                        if(i+r>=0 && i+r<n && j+c>=0 && j+c<m){
                            sum+=img[i+r][j+c];
                            tot++;
                        }
                    }
                }
                ans[i][j]=sum/tot;
            }
        }

        return ans;
    }
};