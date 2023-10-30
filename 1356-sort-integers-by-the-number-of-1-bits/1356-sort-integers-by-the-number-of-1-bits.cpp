#define countbits(x) __builtin_popcount(x)
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int i,int j){
            if(countbits(i)==countbits(j)){
                return i<j;
            }
            return countbits(i)<countbits(j);
        });
        return arr;
    }
};