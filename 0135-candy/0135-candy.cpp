class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> c(n,0);
        vector<int> trav(n,0);
        iota(trav.begin(),trav.end(),0);
        sort(trav.begin(),trav.end(),[&](int x,int y){
          return ratings[x]<ratings[y];
        });
        for(auto i : trav){
          int nbr1=i-1;
          int nbr2=i+1;
          if((nbr1<0 || (nbr1>=0 && c[nbr1]==0)) && (nbr2>=n || (nbr2<n && c[nbr2]==0))){
            c[i]=1;
          }
          else{
            int val=0;
            if(nbr1>=0 && c[nbr1]>0){
              if(ratings[i]==ratings[nbr1]){
                val=max(val,1);
              }
              else{
                val=max(val,c[nbr1]+1);
              }
            }
            if(nbr2<n && c[nbr2]>0){
              if(ratings[i]==ratings[nbr2]){
                val=max(val,1);
              }
              else{
                val=max(val,c[nbr2]+1);
              }
            }
            c[i]=max(val,1);
          }
        }
        int ans=0;
        for(auto e :  c){
          ans+=e;
        }
        return ans;
    }
};