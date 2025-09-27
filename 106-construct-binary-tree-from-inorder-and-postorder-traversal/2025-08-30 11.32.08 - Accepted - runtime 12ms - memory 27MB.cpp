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
    TreeNode* slove(vector<int>& inorder, vector<int>& postorder,int &post,int ind,int end){

        if(ind>end)return NULL;

        int ele=postorder[post--];
        TreeNode* temp=new TreeNode(ele);
        int pos;
        for(int i=0;i<inorder.size();i++){
            if(ele==inorder[i]){
                pos=i;
                break;
            }
        }
        temp->right=slove(inorder,postorder,post,pos+1,end);
        temp->left=slove(inorder,postorder,post,ind,pos-1);
        
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post=postorder.size()-1;
        TreeNode* ans=slove(inorder,postorder,post,0,inorder.size()-1);
        return ans;
    }
};