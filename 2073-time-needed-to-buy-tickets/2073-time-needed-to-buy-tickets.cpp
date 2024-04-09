class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int ans=0;
        int cnt=100;
        int time=0;
        while(cnt--){
            for(int i=0 ; i<n ; i++){
                if(tickets[i]>0){
                    tickets[i]--;
                    time++;
                }
                if(i==k && tickets[i]==0){
                    return time;
                }
            }
        }
        return 0;
    }
};