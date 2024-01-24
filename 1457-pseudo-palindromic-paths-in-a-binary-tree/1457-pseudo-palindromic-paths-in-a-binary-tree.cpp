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
    int help(TreeNode* root,vector<int> &freq){
        if(root->left==NULL && root->right==NULL){
            freq[root->val]++;
            int odd=0;
            for(int i=1 ; i<10 ; i++){
                if(freq[i]&1){
                    odd++;
                }
            }
            freq[root->val]--;
            return odd<=1;
        }

        int curr=0;
        freq[root->val]++;
        if(root->left){
            curr+=help(root->left,freq);
        }
        if(root->right){
            curr+=help(root->right,freq);
        }
        freq[root->val]--;
        return curr;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        int ans=help(root,freq);
        return ans;
    }
};