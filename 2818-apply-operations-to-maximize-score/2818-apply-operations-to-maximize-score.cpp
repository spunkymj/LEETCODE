class Solution {
public:
    long long pow(long long x, long long y, long long p = 1e9 + 7)
    {
        long long res = 1;

        while (y > 0)
        {
            if (y % 2 == 1)
            {
            res = (res * x)%p;
            }
            y = y >> 1;
            x = (x * x)%p;
        }
        return res % p;
    }

    int primeScore(int n) 
    { 
        int p=0; 
        bool chk=false;
        while (n%2 == 0) 
        { 
            chk=true; 
            n = n/2; 
        } 
        if(chk){
            p++;
        }

        for (int i = 3; i <= sqrt(n); i = i+2) 
        { 
            chk=false;
            while (n%i == 0) 
            { 
                chk=true;
                n = n/i; 
            } 
            if(chk){
                p++;
            }
        } 

        chk=false;
        if (n > 2) {
            chk=true;
        }
        if(chk){
            p++;
        }
        return p;
    } 

    int maximumScore(vector<int>& nums, int k) {
        long long res = 1, n = nums.size(), mod = 1000000007;
        vector<int> score, ids(n);
        iota(begin(ids), end(ids), 0);
        sort(begin(ids), end(ids), [&](int i, int j){
            return nums[i] > nums[j];
        });
        for (int x : nums){
            score.push_back(primeScore(x));
        }

        vector<int> nextGreater(n,0);
        vector<int> prevGreater(n,0);

        //next greater
        stack<int> st;
        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && score[st.top()]<=score[i]){
                st.pop();
            }
            if(st.empty()){
                nextGreater[i]=n;
            }
            else{
                nextGreater[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }

        //prev greater
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && score[st.top()]<score[i]){
                st.pop();
            }
            if(st.empty()){
                prevGreater[i]=-1;
            }
            else{
                prevGreater[i]=st.top();
            }
            st.push(i);
        }

        for (int id : ids) {
            int i = prevGreater[id], j = nextGreater[id];

            long long take = min(k, (id - i) * (j - id));
            k -= take;

            res = (res *pow(nums[id], take, mod)) % mod;

            if (k == 0)
                break;
        }

        return res;
    }
};