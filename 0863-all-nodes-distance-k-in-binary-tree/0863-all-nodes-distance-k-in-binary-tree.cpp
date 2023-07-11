/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getparent(unordered_map<TreeNode* , TreeNode*> &mp , TreeNode* root){
        if(!root){
            return ;
        }
        getparent(mp,root->left);
        getparent(mp,root->right);
        if(root->left){
            mp[root->left]=root;
        }
        if(root->right){
            mp[root->right]=root;
        }
    }

    void solve(TreeNode* target , int k ,vector<int> &ans, unordered_map<TreeNode*,bool> &vis,unordered_map<TreeNode* , TreeNode*> &mp){
        if(!target || vis[target]){
            return;
        }
        if(k==0){
            ans.push_back(target->val);
            return;
        }
        vis[target]=true;
        solve(target->left,k-1,ans,vis,mp);
        solve(target->right,k-1,ans,vis,mp);
        solve(mp[target],k-1,ans,vis,mp);
        vis[target]=false;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> mp;
        mp[root]=NULL;
        getparent(mp , root);
        unordered_map<TreeNode*,bool> vis;
        vector<int> ans;
        solve(target,k,ans,vis,mp);
        return ans;
    }
};