class MyHashMap {
public:
    int prime;
    vector<list<pair<int,int>>>bucket;

    MyHashMap():prime(100009),bucket(prime,list<pair<int,int>>()) {
        
    }
    
    void put(int key, int value) {
        int hash=key%prime;
        auto iter=bucket[hash].begin();
        for(;iter!=bucket[hash].end();iter++){
            if((*iter).first==key){
                (*iter).second=value;
                return;
            }
        }
        bucket[hash].push_back({key,value});
    }
    
    int get(int key) {
        int hash=key%prime;
        for(auto iter=bucket[hash].begin();iter!=bucket[hash].end();iter++){
            if((*iter).first==key){
                return (*iter).second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hash=key%prime;
        for(auto iter=bucket[hash].begin();iter!=bucket[hash].end();iter++){
            if((*iter).first==key){
                bucket[hash].erase(iter);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */