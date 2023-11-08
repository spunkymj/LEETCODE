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
    int dfs(TreeNode* node,int &ans){
        vector<int> have(3,0);
        if(node->left){
            int val=dfs(node->left,ans);
            have[val]=1;
        }
        if(node->right){
            int val=dfs(node->right,ans);
            have[val]=1;
        }
        if(have[0]){
            ans++;
            return 2;
        }
        if(have[2]){
            return 1;
        }
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(dfs(root,ans)==0){
            ans++;
        }
        return ans;
    }
};