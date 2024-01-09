/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       vector<int> v1,v2;
       tra(root1 , v1);
       tra(root2 , v2);
       if(v1.size()!=v2.size()){
           return false;
       }
       for(int i=0 ; i<v1.size() ; i++){
           if(v1[i]!=v2[i]){
               return false;
           }
       }
        return true;
    }

    void tra(TreeNode* root , vector<int> &v){
        if(!root){
            return ;
        }
        if(!root->right && !root->left){
            v.push_back(root->val);
            return ;
        }
        tra(root->left,v);
        tra(root->right,v);
    }
};