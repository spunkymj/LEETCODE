class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        
        int k = 0;
        int nn=n;
        while (nn) {
            k++;
            nn=nn>>1;
        }
        k--;
        
        return (1 << (k + 1)) - 1 - minimumOneBitOperations(n ^ ((1 << (k))));
    }
};