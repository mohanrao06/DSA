class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key,int _val){
            key=_key;
            val=_val;

        }
    };
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int cap;
    map<int,Node*> mpp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* ansNode=mpp[key];
            int ans=ansNode->val;
            mpp.erase(key);
            deleteNode(ansNode);
            addNode(ansNode);
            mpp[key]=head->next;
            return ans;

        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            mpp.erase(key);
            deleteNode(node);
        }
        if(cap==mpp.size()){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mpp[key]=head->next;
    }
    void addNode(Node* node){
        Node* currNode=head->next;
        head->next=node;
        node->next=currNode;
        node->prev=head;
        currNode->prev=node;

    }
    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */