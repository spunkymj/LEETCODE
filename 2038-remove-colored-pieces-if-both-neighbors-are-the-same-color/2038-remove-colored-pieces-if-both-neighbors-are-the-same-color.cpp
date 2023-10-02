class Solution {
public:
    bool winnerOfGame(string colors) {
        vector<vector<int>> cont(2);
        int n=colors.size();
        for(int i=0 ; i<n ; i++){
            char curr=colors[i];
            int j=i;
            while(i<n && colors[i]==curr){
                i++;
            }
            i--;
            cont[curr-'A'].push_back(i-j+1);
        }
        int Alice_moves=0;
        int Bob_moves=0;
        for(auto e : cont[0]){
            Alice_moves+=max(0,e-2);
        }
        for(auto e : cont[1]){
            Bob_moves+=max(0,e-2);
        }
        return Alice_moves>Bob_moves;
    }
};