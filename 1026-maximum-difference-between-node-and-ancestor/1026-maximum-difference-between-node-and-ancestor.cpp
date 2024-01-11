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
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        solve(root,root->val,root->val,ans);
        return ans;
    }

    void solve(TreeNode* root , int mini , int maxi, int &ans){
        if(!root){
            return ;
        }
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        ans=max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
        solve(root->left,mini,maxi,ans);
        solve(root->right,mini,maxi,ans);
    }
};