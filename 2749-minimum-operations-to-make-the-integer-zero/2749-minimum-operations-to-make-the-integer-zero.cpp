#define ll long long

int set_bit_count(ll num){
    int ret=0;
    while(num){
        ret+=num&1;
        num=num>>1;
    }
    return ret;
}


class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // target_setbit_count() <= k <= target
        //eg 5 = 4+1 = 2+2+1 = 2+1+1+1+1 = 1+1+1+1+1
        for(ll k=1 ; k<=60 ; k++){
            ll target=num1-num2*k;
            if(target>=0 && ((set_bit_count(target))<=k && k<=target)){
                return k;
            }
        }
        return -1;
    }
};