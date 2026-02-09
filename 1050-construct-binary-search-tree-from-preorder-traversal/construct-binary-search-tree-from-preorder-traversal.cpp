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
    TreeNode* fun(vector<int>& preorder,int mini,int maxi,int &ind){
        if(ind==preorder.size() || preorder[ind]<mini || preorder[ind]>maxi)return NULL;
        TreeNode* root=new TreeNode(preorder[ind++]);
        root->left=fun(preorder,mini,root->val,ind);
        root->right=fun(preorder,root->val,maxi,ind);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return fun(preorder,INT_MIN,INT_MAX,ind);
    }
};