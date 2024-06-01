class MyHashSet {
public:
    int prime;
    vector<list<int>>bucket;

    MyHashSet(): prime(100009),bucket(prime,list<int>()){
        
    }
    
    void add(int key) {
        int hash=key%prime;
        auto iter=bucket[hash].begin();
        for(;iter!=bucket[hash].end();iter++){
            if(*iter==key)return;
        }
        bucket[hash].push_back(key);
    }
    
    void remove(int key) {
        int hash=key%prime;
        for(auto iter=bucket[hash].begin();iter!=bucket[hash].end();iter++){
            if(*iter==key){
                bucket[hash].erase(iter);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int hash=key%prime;
        for(auto iter=bucket[hash].begin();iter!=bucket[hash].end();iter++){
            if(*iter==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */