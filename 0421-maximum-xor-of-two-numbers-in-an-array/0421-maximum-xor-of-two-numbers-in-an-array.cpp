class Node{
    private :
    vector<Node*> next;
    
    public :

    Node(){
        next.resize(2,NULL);
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
        Node* curr=root;
        for(int i=31 ; i>=0 ; i--){
            int bit=(num>>i)&1;
            if(!curr->containKey(bit)){
                curr->put(bit,new Node());
            }
            curr=curr->get(bit);
        }
    }

    int maxXor(int num){
        int maxi=0;
        Node* curr=root;
        for(int i=31 ; i>=0 ; i--){
            int bit=(num>>i)&1;
            if(curr->containKey(!bit)){
                maxi+=(1<<i);
                curr=curr->get(!bit);
            }
            else{
                curr=curr->get(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie T;
        for(auto &ele : nums){
            T.insert(ele);
        }
        int ans=0;
        for(auto &ele : nums){
            ans=max(ans,T.maxXor(ele));
        }
        return ans;
    }
};