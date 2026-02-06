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
    unordered_map<int,int> mp;
    int ind = 0; 
    TreeNode* build_tree(vector<int>& preorder, vector<int>& inorder,int l,int r){
        if(l>r)return NULL;
        int ele=preorder[ind++];
        int pos=mp[ele];
        TreeNode* root=new TreeNode(ele);
        root->left=build_tree(preorder,inorder,l,pos-1);
        root->right=build_tree(preorder,inorder,pos+1,r);
        return root;



    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();

        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* ans=build_tree(preorder,inorder,0,n-1);
        return ans;
    }
};