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
    int maxDepth(TreeNode* root,int &ans) {
        if(!root){
            return 0;
        }
        int height_left=maxDepth(root->left,ans);
        int height_right=maxDepth(root->right,ans);

        ans=max(ans,height_left+height_right);
        return 1+max(height_left,height_right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        maxDepth(root,ans);
        return ans;
    }
};