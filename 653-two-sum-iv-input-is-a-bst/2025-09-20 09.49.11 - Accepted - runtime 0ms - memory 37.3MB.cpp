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
    void inorder(TreeNode* root,vector<int> &in){
        if(!root)return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);



    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root,in);
        int i=0;
        int j=in.size()-1;
        while(i<j){
            if(in[i]+in[j]==k)return true;
            else if(in[i]+in[j]>k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};