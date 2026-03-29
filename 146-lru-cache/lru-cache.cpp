class Node{
    public:
    Node* next;
    Node* prev;
    int data;
    int key;

    Node(int val,int k){
        data=val;
        key=k;
    }
    
};
class LRUCache {
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int size=0;
    map<int,Node*> mp;
public:
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* ansnode=mp[key];
            int ans=ansnode->data;
            deleteNode(ansnode);
            addNode(ansnode);
            mp[key]=ansnode;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* ansnode=mp[key];
            mp.erase(key);
            int ans=ansnode->data;
            deleteNode(ansnode);
        }
        if(size==mp.size()){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode=new Node(value,key);
        addNode(newNode);
        mp[key]=newNode;


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