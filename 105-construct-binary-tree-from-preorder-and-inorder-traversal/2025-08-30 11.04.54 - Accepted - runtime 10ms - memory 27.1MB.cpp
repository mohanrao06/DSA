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
    int find(vector<int>& inorder,int ele){
        int ans=0;
        for(int i=0;i<inorder.size();i++){
            if(ele==inorder[i]){
                ans=i;
                break;
            }

        }
        return ans;
    }
    TreeNode* slove(vector<int>& preorder, vector<int>& inorder,int &pre,int ind,int end){
        if(ind>end)return NULL;
        int ele=preorder[pre++];
        TreeNode* temp=new TreeNode(ele);
        int pos=find(inorder,ele);
        temp->left=slove(preorder,inorder,pre,ind,pos-1);
        temp->right=slove(preorder,inorder,pre,pos+1,end);
        return temp;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre=0;
        TreeNode* ans=slove(preorder,inorder,pre,0,inorder.size()-1);
        return ans;
    }
};