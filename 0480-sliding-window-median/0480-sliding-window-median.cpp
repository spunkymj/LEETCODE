class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        multiset<long long> st;
        for(int i=0 ; i<k ; i++){
    	    st.insert(a[i]);
        }
        auto mid=next(st.begin(),(k-1)/2);
        vector<double> ans;
        ans.push_back((double)(*mid+*(next(mid,1-(k&1))))/(double)2);
        for(int i=k ; i<n ; i++){
    	    st.insert(a[i]);
        	if(a[i]<*mid){
    	    	mid--;
    	    }
    	    if(a[i-k]<=*mid){
    		    mid++;
    	    }
    	    auto it=st.lower_bound(a[i-k]);
    	    st.erase(it);
            ans.push_back((double)(*mid+*(next(mid,1-(k&1))))/(double)2);
        }
        return ans;
    }
};