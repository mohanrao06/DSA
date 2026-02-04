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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;
        if(!root)return ans;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int level=it.second.first;
            int col=it.second.second;
            mp[col].push_back({level,node->val});

            if(node->left)q.push({node->left,{level+1,col-1}});
            if(node->right)q.push({node->right,{level+1,col+1}});
        }
        for(auto it:mp){
            auto vec=it.second;
            sort(vec.begin(),vec.end());
            vector<int> colvals;
            for(auto i:vec){
                colvals.push_back(i.second);
            }
            ans.push_back(colvals);
        }
        return ans;

    }
};