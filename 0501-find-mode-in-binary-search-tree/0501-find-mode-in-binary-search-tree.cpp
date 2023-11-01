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
    unordered_map<int,int> mp;

    void Mode(TreeNode* root) {
        mp[root->val]++;
        if(root->left){
            Mode(root->left);
        }
        if(root->right){
            Mode(root->right);
        }

    }

    vector<int> findMode(TreeNode* root) {
        mp[root->val]++;
        if(root->left){
            Mode(root->left);
        }
        if(root->right){
            Mode(root->right);
        }
        int maxi=0;
        for(auto m : mp){
            maxi=max(maxi,m.second);
        }
        vector<int> ans;
        for(auto m : mp){
            if(m.second==maxi){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};