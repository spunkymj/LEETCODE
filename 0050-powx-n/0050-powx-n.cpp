class Solution {
public:
    double myPow(double x, int n) {
        long nn=n;
        return (pow(x,nn));
    }
    
    double pow(double x, long n)
    {
        if(n==0){
           return 1;
        }
        if(n<0){
            n= -n;
            x= 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
};