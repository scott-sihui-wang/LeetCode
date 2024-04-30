class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node *prev,*next;
        Node(){}
        Node(int k,int v,Node* p,Node* n){
            key=k;
            value=v;
            prev=p;
            next=n;
        }
    };
    Node *head,*tail;
    unordered_map<int,Node*>dict;
    int cap;
    int cnt;
    LRUCache(int capacity) {
        cap=capacity;
        cnt=0;
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(dict.find(key)==dict.end()){
            return -1;
        }
        else{
            dict[key]->prev->next=dict[key]->next;
            dict[key]->next->prev=dict[key]->prev;
            Node* node=new Node(key,dict[key]->value,head,head->next);
            head->next->prev=node;
            head->next=node;
            delete dict[key];
            dict[key]=node;
            return dict[key]->value;
        }
    }
    
    void put(int key, int value) {
        if(cnt<cap){
            if(dict.find(key)==dict.end()){
                cnt++;
                Node* node=new Node(key,value,head,head->next);
                head->next->prev=node;
                head->next=node;
                dict[key]=node;
            }
            else{
                Node* node1=dict[key];
                node1->prev->next=node1->next;
                node1->next->prev=node1->prev;
                delete node1;
                Node* node2=new Node(key,value,head,head->next);
                head->next->prev=node2;
                head->next=node2;
                dict[key]=node2;
            }    
        }
        else{
            if(dict.find(key)==dict.end()){
                Node* node1=tail->prev;
                dict.erase(node1->key);
                tail->prev=tail->prev->prev;
                node1->prev->next=tail;
                delete node1;
                Node* node2=new Node(key,value,head,head->next);
                head->next->prev=node2;
                head->next=node2;
                dict[key]=node2;
            }
            else{
                Node* node1=dict[key];
                node1->prev->next=node1->next;
                node1->next->prev=node1->prev;
                delete node1;
                Node* node2=new Node(key,value,head,head->next);
                head->next->prev=node2;
                head->next=node2;
                dict[key]=node2;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */