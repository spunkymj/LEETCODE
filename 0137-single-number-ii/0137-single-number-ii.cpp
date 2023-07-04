class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //   3 is written in binary as 1 1 (x1 x0)
        int x0=0;
        int x1=0;
        for(int &ele : nums){
            x1=x1^(x0&ele);
            x0=x0^ele;
            int mask=~(x0&x1); 
            x1=x1&mask;
            x0=x0&mask;
        }
        return x0;
    }
};