class Solution {
public:
    int solve(int i,vector<string>& arr,int mask)
{
    if(i==arr.size()){
        return 0;
    }
    int temp=mask;
    for(char c : arr[i]){
        if((mask>>(c-'a'))&1){
            return solve(i+1,arr,temp);
        }
        mask|=(1<<(c-'a'));
    }
    return max((int)solve(i+1,arr,temp),(int)(arr[i].size()+solve(i+1,arr,mask)));

 }

    int maxLength(vector<string>& arr) {
        return solve(0  ,arr , 0);
    }
};