class MyLinkedList {
    struct node{
        int val;
        node* next;
        node(int _val){
            val=_val;
            next=nullptr;
        }
        node(int _val,node* _next){
            val=_val;
            next=_next;
        }
    };
public:
    node *head,*tail;
    MyLinkedList() {
        head=nullptr;
        tail=nullptr;
    }
    
    int get(int index) {
        if(index<0)return -1;
        node *ptr=head;
        int i=0;
        while(i<index && ptr!=nullptr){
            ptr=ptr->next;
            i++;
        }
        if(ptr==nullptr)return -1;
        return ptr->val;
    }
    
    void addAtHead(int val) {
        if(head==nullptr && tail==nullptr){
            head=new node(val);
            tail=head;
        }
        else{
            node *ptr=new node(val,head);
            head=ptr;
        }
    }
    
    void addAtTail(int val) {
        if(head==nullptr && tail==nullptr){
            tail=new node(val);
            head=tail;
        }
        else{
            node *ptr=new node(val);
            tail->next=ptr;
            tail=ptr;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index<0)return;
        if(index==0){
            addAtHead(val);
            return;
        }
        if(head==nullptr && tail==nullptr)return;
        node *prev=head,*ptr=head->next;
        int i=1;
        while(i<index && ptr!=nullptr){
            prev=prev->next;
            ptr=ptr->next;
            i++;
        }
        if(i==index){
            prev->next=new node(val,ptr);
            if(ptr==nullptr){
                tail=prev->next;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || head==nullptr)return;
        if(index==0){
            node* ptr=head;
            head=head->next;
            delete ptr;
            if(head==nullptr)tail=nullptr;
            return;
        }
        int i=1;
        node *prev=head,*ptr=head->next;
        while(i<index && ptr!=nullptr){
            prev=prev->next;
            ptr=ptr->next;
            i++;
        }
        if(ptr!=nullptr){
            prev->next=ptr->next;
            delete ptr;
            if(prev->next==nullptr){
                tail=prev;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */