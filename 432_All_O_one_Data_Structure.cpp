class AllOne {
public:

    unordered_map<string,pair<int,list<string>::iterator>>dict;//key->{freq,list node ptr}
    map<int,list<string>>freq;//freq->list of strings with certain frequency

    AllOne() {

    }
    
    void inc(string key) {
        if(dict.find(key)==dict.end()){
            freq[1].push_back(key);
            list<string>::iterator iter=freq[1].end();
            --iter;
            dict[key]={1,iter};
        }
        else{
            freq[dict[key].first].erase(dict[key].second);
            if(freq[dict[key].first].size()==0){
                freq.erase(dict[key].first);
            }
            dict[key].first+=1;
            freq[dict[key].first].push_back(key);
            list<string>::iterator iter=freq[dict[key].first].end();
            iter--;
            dict[key].second=iter;
        }
    }
    
    void dec(string key) {
        if(dict.find(key)!=dict.end()){
            freq[dict[key].first].erase(dict[key].second);
            if(freq[dict[key].first].size()==0){
                freq.erase(dict[key].first);
            }
            dict[key].first-=1;
            if(dict[key].first==0){
                dict.erase(key);
            }
            else{
                freq[dict[key].first].push_back(key);
                list<string>::iterator iter=freq[dict[key].first].end();
                --iter;
                dict[key].second=iter;
            }
        }
    }
    
    string getMaxKey() {
        if(freq.size()==0)return string("");
        map<int,list<string>>::iterator iter=freq.end();
        --iter;
        return freq[iter->first].front();
    }
    
    string getMinKey() {
        if(freq.size()==0)return string("");
        map<int,list<string>>::iterator iter=freq.begin();
        return freq[iter->first].front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */