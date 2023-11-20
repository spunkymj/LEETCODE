class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int p=0,g=0,m=0;
        int curr=0;
        travel.push_back(0);
        for(int i=0 ; i<garbage.size() ; i++){
            int cnt=0;
            for(auto e  : garbage[i]){
                cnt+=(e=='P');
            }
            if(cnt>0){
                p+=curr+cnt;
                curr=0;
            }
            curr+=travel[i];
        }
        curr=0;
        for(int i=0 ; i<garbage.size() ; i++){
            int cnt=0;
            for(auto e  : garbage[i]){
                cnt+=(e=='G');
            }
            if(cnt>0){
                g+=curr+cnt;
                curr=0;
            }
            curr+=travel[i];
        }
        curr=0;
        for(int i=0 ; i<garbage.size() ; i++){
            int cnt=0;
            for(auto e  : garbage[i]){
                cnt+=(e=='M');
            }
            if(cnt>0){
                m+=curr+cnt;
                curr=0;
            }
            curr+=travel[i];
        }
        travel.pop_back();
        return p+g+m;
    }
};