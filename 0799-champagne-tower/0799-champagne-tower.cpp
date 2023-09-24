class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> champange(query_row+1,vector<double> (query_row+2,0));
        champange[0][1]=poured;
        int current_row=1;
        while(current_row!=query_row+1){
            for(int i=0 ; i<=current_row ; i++){
                champange[current_row][i+1]=max((champange[current_row-1][i+1]-(double)1)/(double)2,(double)0)+max((champange[current_row-1][i]-(double)1)/(double)2,(double)0);
            }
            current_row++;
        }
        return min(champange[query_row][query_glass+1],(double)1);
    }
};