class MinStack {
public:
    int arr[30000];
    int arr_m[30000];
    int _top;
    
    MinStack() {
        _top=-1;
    }
    
    void push(int val) {
        arr[++_top]=val;
        if(_top==0){
            arr_m[_top]=val;
        }
        else{
            arr_m[_top]=min(arr_m[_top-1],val);
        }
    }
    
    void pop() {
        _top--;
    }
    
    int top() {
        return arr[_top];
    }
    
    int getMin() {
        return arr_m[_top];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */