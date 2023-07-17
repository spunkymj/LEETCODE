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
            if(curr==NULL){
                return -1;
            }
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> q(queries.size(),0);
        iota(q.begin(),q.end(),0);
        sort(q.begin(),q.end(),[&](int i,int j){
            return queries[i][1]<queries[j][1];
        });

        vector<int> ans(queries.size(),-1);
        int ptr=0;
        Trie T;
        for(auto &i : q){
            while(ptr<nums.size() && nums[ptr]<=queries[i][1]){
              T.insert(nums[ptr]);
              ptr++;  
            }
            ans[i]=T.maxXor(queries[i][0]);
        }
        return ans;
    }
};