/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void make_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* parent=q.front();
            q.pop();
            if(parent->left){
                mp[parent->left]=parent;
                q.push(parent->left);
            }
            if(parent->right){
                mp[parent->right]=parent;
                q.push(parent->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        make_parent(root,parent);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int dist=0;
        while(!q.empty()){
            int size=q.size();
            if(dist==k)break;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }
            }
            dist++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

    }
};