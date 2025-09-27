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
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            int size=q.size();
            long long l=q.front().second;
            long long r=q.back().second;
            ans=max(ans,r-l+1);
            while(size--){
                auto p=q.front();
                q.pop();
                TreeNode* node=p.first;
                long long idx=p.second-l;
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