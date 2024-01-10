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
    void getparent(unordered_map<TreeNode* , TreeNode*> &mp , TreeNode* root,int start,TreeNode* &target){
        if(!root){
            return ;
        }

        if(root->val==start){
            target=root;
        }
        getparent(mp,root->left,start,target);
        getparent(mp,root->right,start,target);
        if(root->left){
            mp[root->left]=root;
        }
        if(root->right){
            mp[root->right]=root;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*> mp;
        mp[root]=NULL;
        TreeNode* target;
        getparent(mp , root,start,target);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        q.push(target);
        int mintime=0;
        while(!q.empty()){
            bool flag=0;
            int s=q.size();
            for(int i=0 ; i<s ; i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    flag=1;
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    flag=1;
                    vis[node->right]=true;
                }
                if(mp[node] && !vis[mp[node]]){
                    q.push(mp[node]);
                    flag=1;
                    vis[mp[node]]=true;
                }
            }
            if(flag){
                mintime++;
            }
        }
        return mintime;
    }
};