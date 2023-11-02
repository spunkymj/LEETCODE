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
    pair<int,int>  getsum(TreeNode* root,int &ans){
        int sum=root->val;
        int n=1;
        if(root->left){
            pair<int,int> p=getsum(root->left,ans);
            sum+=p.second;
            n+=p.first;
        }
        if(root->right){
            pair<int,int> p=getsum(root->right,ans);
            sum+=p.second;
            n+=p.first;
        }

        int avg=sum/n;
        ans+=((root->val)==avg);
        
        return {n,sum};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        getsum(root,ans);
        return ans;
    }
};