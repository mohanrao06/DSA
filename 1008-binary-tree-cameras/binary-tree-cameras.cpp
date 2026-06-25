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
    int ans;
    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(left == -1 || right == -1) {
            ans++;
            return 1;
        }

        if(left == 1 || right == 1) {
            return 0;
        }

        return -1;


    }
    // int top(TreeNode* root,int ans1){
        
    // }
    // int bottom(TreeNode* root,int ans2){

    // }
    int minCameraCover(TreeNode* root) {
        ans=0;
        if(dfs(root) == -1)
            ans++;

        return ans;
    }
    
};