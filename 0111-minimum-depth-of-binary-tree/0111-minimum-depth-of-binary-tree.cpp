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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        int ret=1e9;
        if(root->left){
            ret=min(1+minDepth(root->left),ret);
        }
        if(root->right){
            ret=min(1+minDepth(root->right),ret);
        }
        return ret;
    }
};