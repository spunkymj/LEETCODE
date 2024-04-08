class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(auto e : students){
            q.push(e);
        }
        int itr=0;
        int n=sandwiches.size();
        int cnt=0;
        while(itr<n && cnt<q.size()){
            if(q.front()==sandwiches[itr]){
                q.pop();
                cnt=0;
                itr++;
            }
            else{
                q.push(q.front());
                q.pop();
                cnt++;
            }
        }
        return (int)q.size();
    }
};