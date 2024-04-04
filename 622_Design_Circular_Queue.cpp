class MyCircularQueue {
public:
    int* data;
    int begin;
    int end;
    int capacity;
    
    MyCircularQueue(int k) {
        data=new int[k+1];
        begin=0;
        end=0;
        capacity=k;
    }
    
    bool enQueue(int value) {
        if((end+1)%(capacity+1)==begin){
            return false;
        }
        else{
            data[end]=value;
            end=(end+1)%(capacity+1);
            return true;
        }
    }
    
    bool deQueue() {
        if(begin==end){
            return false;
        }
        else{
            begin=(begin+1)%(capacity+1);
            return true;
        }
    }
    
    int Front() {
        if(begin==end){
            return -1;
        }
        else{
            return data[begin];
        }
    }
    
    int Rear() {
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */