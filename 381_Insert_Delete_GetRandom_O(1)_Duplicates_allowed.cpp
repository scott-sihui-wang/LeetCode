class RandomizedCollection {
public:
    vector<int>arr;
    unordered_map<int,set<int>>idx;

    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans=(idx.find(val)==idx.end());
        arr.push_back(val);
        idx[val].insert(arr.size()-1);
        return ans;
    }
    
    bool remove(int val) {
        bool ans=(idx.find(val)!=idx.end());
        if(ans){
            auto iter=idx[val].begin();
            int j=*iter;
            arr[j]=arr[arr.size()-1];
            idx[val].erase(j);
            idx[arr[arr.size()-1]].insert(j);
            idx[arr[arr.size()-1]].erase(arr.size()-1);
            if(idx[val].size()==0){
                idx.erase(val);
            }
            arr.pop_back();
        }
        return ans;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */