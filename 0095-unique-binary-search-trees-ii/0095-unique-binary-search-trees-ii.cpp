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
    vector<TreeNode*> solve(int l,int r){
        if(l>r){
            return {NULL};
        }
        vector<TreeNode*> curr;
        for(int i=l;i<=r ; i++){
            vector<TreeNode*> leftBst=solve(l,i-1);
            vector<TreeNode*> rightBst=solve(i+1,r);
            for(auto &u : leftBst){
                for(auto &v : rightBst){
                    TreeNode* root=new TreeNode(i);
                    root->left=u;
                    root->right=v;
                    curr.push_back(root);
                }
            }
        }
        return curr;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans=solve(1,n);
        return ans;
    }
};