#define vi vector<int>

class Solution {
public:
    
//Previous smaller Element

vector<int> prevSmaller(vi &arr)
{
    stack<int> s;
    s.push(0);
    vi prevg(arr.size(),-1);
 
    for (int i = 1; i < arr.size(); i++) {
        while (s.empty() == false && arr[s.top()] >= arr[i]){
            s.pop();
        }

        if(!s.empty()){
          prevg[i]=s.top();
        }

        s.push(i);
    }

    return prevg;
}


//Next smaller Element

vector<int> nextSmaller(vi &arr)
{
    stack<int> s;
    s.push(arr.size()-1);
    vi nextg(arr.size(),arr.size());

    for (int i = arr.size()-2 ; i>=0 ; i--) {
        while (s.empty() == false && arr[s.top()] > arr[i]){
            s.pop();
        }

        if(!s.empty()){
          nextg[i]=s.top();
        }

        s.push(i);
    }
    return nextg;
}

    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
        vi left=prevSmaller(a);
        vi right=nextSmaller(a);
        long long ans=0;
        for(int i=0 ; i<=n-1 ;i++){
            ans+=(long long)(right[i]-i)*(long long)(i-left[i])*(long long)a[i];
            ans%=(1000000007);
        }
        return ans;
    }
};