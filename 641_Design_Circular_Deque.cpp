class MyCircularDeque {
public:
    int* data;
    int begin;
    int end;
    int capacity;
    
    MyCircularDeque(int k) {
        data=new int[k+1];
        begin=0;
        end=0;
        capacity=k;
    }
    
    bool insertFront(int value) {
        if((end+1)%(capacity+1)==begin){
            return false;
        }
        else{
            if(begin==0){
                begin=capacity;
                data[begin]=value;
            }
            else{
                data[--begin]=value;
            }
            return true;
        }
    }
    
    bool insertLast(int value) {
        if((end+1)%(capacity+1)==begin){
            return false;
        }
        else{
            data[end]=value;
            end=(end+1)%(capacity+1);
            return true;
        }
    }
    
    bool deleteFront() {
        if(begin==end){
            return false;
        }
        else{
            begin=(begin+1)%(capacity+1);
            return true;
        }
    }
    
    bool deleteLast() {
        if(begin==end){
            return false;
        }
        else{
            if(end==0){
                end=capacity;
            }
            else{
                end--;
            }
            return true;
        }
    }
    
    int getFront() {
        if(begin==end){
            return -1;
        }
        else{
            return data[begin];
        }
    }
    
    int getRear() {
        if(begin==end){
            return -1;
        }
        else{
            if(end==0){
                return data[capacity];
            }
            else{
                return data[end-1];
            }
        }
    }
    
    bool isEmpty() {
        return begin==end;
    }
    
    bool isFull() {
        return (end+1)%(capacity+1)==begin;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */