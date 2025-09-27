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
    void slove(TreeNode* root,int &cnt){
        if(!root)return;
        cnt++;
        slove(root->left,cnt);
        slove(root->right,cnt);

    }
    int countNodes(TreeNode* root) {
        int cnt=0;
        slove(root,cnt);
        return cnt;
    }
};