/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> level;
        if(!root)return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<Node*> temp;
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                temp.push_back(node);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            level.push_back(temp);
        }

        for(auto it:level){
            int size=it.size();
            if(size==1)it[0]->next=NULL;
            it[size-1]->next=NULL;
            for(int i=0;i<size-1;i++){
                Node* node=it[i];
                node->next=it[i+1];
            }
        }
        return root;
    }
};