class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            vector<int> x={1};
            return x;
        }
        if(rowIndex==1){
            vector<int> x={1,1};
            return x;
        }
        
        vector<int> x={1,1};
        for(int i=0 ; i <= rowIndex-2 ; i++){
            int pos=x.size()-1;
            while(pos>=1){
                x[pos]=x[pos]+x[pos-1];
                pos--;
            }
            x.push_back(1);
        }
        return x;
    }
};