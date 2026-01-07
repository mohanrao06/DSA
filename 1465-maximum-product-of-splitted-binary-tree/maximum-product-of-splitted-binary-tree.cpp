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
    void Treesum(TreeNode* root,int &sum){
        if(!root)return;
        sum+=root->val;
        Treesum(root->left,sum);
        Treesum(root->right,sum);
    }
    long long  fun(TreeNode* root,long long &ans,int sum){
        if(!root){
            return 0;
        }
        long left = fun(root->left,ans,sum);
        long right = fun(root->right,ans,sum);
        long long subsum=root->val+left+right;
        ans=max(ans,subsum*(sum-subsum));
        return subsum;

    }
    int maxProduct(TreeNode* root) {
         
        int sum=0;
        Treesum(root,sum);
        long long ans=0;
        fun(root,ans,sum);
        return ans%1000000007;


    }
};  