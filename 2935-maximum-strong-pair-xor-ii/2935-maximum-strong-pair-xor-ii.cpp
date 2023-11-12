class Node{
    public :
    vector<Node*> next;
    int freq;
    
    public :

    Node(){
        next.resize(2,NULL);
        freq=0;
    }

    bool containKey(int bit){
        return next[bit]!=NULL;
    }

    void put(int bit,Node* node){
        next[bit]=node;
    }

    Node* get(int bit){
        return next[bit];
    }
};

class Trie{
    private :
    Node* root;

    public  :

    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node* node=root;
        for(int i=31 ; i>=0 ; i--){
            int bit=(num>>i)&1;
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
            node->freq++;
        }
    }

    void remove(int num){
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containKey(bit)) {
                node = node->get(bit);
                node->freq--;
            } 
            else {
                break;
            }
        }
    }

    int MaxXor(int num) {
        Node* node = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containKey(1 - bit) && node->get(1 - bit)->freq > 0) {
                res = res | (1 << i);
                node = node->get(1 - bit);
            } 
            else {
                if(node->containKey(bit) && node->get(bit)->freq > 0){ 
                    node = node->get(bit);
                }
                else {
                    return 0;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        Trie T;
        T.insert(nums[0]);
        int st=0;
        int n=nums.size();
        for(int i=1; i<n ; i++){
            while((st<i) && (nums[i]-nums[st]>nums[st])){
                T.remove(nums[st]);
                st++;
            }
            ans=max(ans,T.MaxXor(nums[i]));
            T.insert(nums[i]);
        }
        return ans;
    }
};