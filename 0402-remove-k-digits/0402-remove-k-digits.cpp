class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size()){
            return "0";
        }
        int n=num.size();
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
        int last=-1;
        for(int i=0 ; i<k+1 ; i++){
            pq.push({num[i],i});
        }
        string ans="";
        ans+=pq.top().first;
        last=pq.top().second;
        pq.pop();
        int rmv=k;
        while(!pq.empty() && rmv>0 && pq.top().second<last){
            pq.pop();
            rmv--;
        }
        for(int i=k+1; i<n ; i++){
            pq.push({num[i],i});
            // cout<<num[i]<<" ";
            if(!pq.empty()){
                ans+=pq.top().first;
                last=pq.top().second;
                pq.pop();
            }
            // cout<<ans<<endl;
            while(!pq.empty() && rmv>0 && pq.top().second<last){
                pq.pop();
                rmv--;
            }
        }
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        if(i==ans.size()){
            return "0";
        }
        string ret="";
        for(int k=i ; k<ans.size() ; k++){
            ret+=ans[k];
        }
        return ret;
    }
};