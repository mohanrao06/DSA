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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=INT_MIN;
        int level=0;
        int l=0;
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            l++;
            for(int i=0;i<size;i++){
                TreeNode* Node=q.front();
                q.pop();
                sum+=Node->val;

                if(Node->left)q.push(Node->left);
                if(Node->right)q.push(Node->right);
                
            }
            if(sum>ans){
                ans=sum;
                level=l;
            }
        }
        return level;
    }
};