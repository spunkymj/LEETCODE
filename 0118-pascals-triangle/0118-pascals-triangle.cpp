class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    
        vector<vector<int>> x(numRows,{1});
        for(int i=0 ; i < numRows-1 ; i++){
            for (int k=0 ; k < x[i].size()-1 ; k++){
                x[i+1].push_back(x[i][k]+x[i][k+1]);
            }
            x[i+1].push_back(1);
        }
        return x;
    }
};