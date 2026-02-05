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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        if(!root)return ans;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long Lind=q.front().second;
            long long Rind=q.back().second;
            ans=max(ans,Rind-Lind+1);
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                TreeNode* node=it.first;
                long long idx=it.second-Lind;
                if(node->left){
                    q.push({node->left,idx*2+1});
                }
                if(node->right){
                    q.push({node->right,idx*2+2});
                }

            }
        }
        
        return (int)ans;

    }
};