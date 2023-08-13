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
        for (int id : ids) {
            int i = id, j = id;
            while (i > 0 && score[i - 1] < score[id])
                --i;
            while (j < n && score[j] <= score[id])
                ++j;
            
            long long take = min(k, (id - i + 1) * (j - id));
            k -= take;
            res = (res *pow(nums[id], take, mod)) % mod;
            if (k == 0)
                break;
        }
        return res;
    }
};