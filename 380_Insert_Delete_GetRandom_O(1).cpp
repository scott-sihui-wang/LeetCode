class RandomizedSet {
public:
    unordered_map<int,int> dict;
    vector<int> vect;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(dict.find(val)==dict.end()){
            dict[val]=vect.size();
            vect.push_back(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(dict.find(val)==dict.end()){
            return false;
        }
        else{
            vect[dict[val]]=vect.back();
            dict[vect[dict[val]]]=dict[val];
            vect.pop_back();
            dict.erase(val);  
            return true;
        }
    }
    
    int getRandom() {
        return vect[rand()%vect.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */