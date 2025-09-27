class MyStack {
public:
    MyStack() {
        
    }
    queue<int> qq;
    
    void push(int x) {
        int size=qq.size();
        qq.push(x);
        for(int i=1;i<=size;i++){
            qq.push(qq.front());
            qq.pop();
        }
    }
    
    int pop() {
        int ele=qq.front();
        qq.pop();
        return ele;
    }
    
    int top() {
        return qq.front();

    }
    
    bool empty() {
        return qq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */