class LFUCache {
public:
    unordered_map<int,list<pair<int,int>>> freq;
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>> dict;
    int size,cap;
    int minFreq;

    LFUCache(int capacity) {
        size=0;
        cap=capacity;
        minFreq=0;
    }
    
    int get(int key) {
        bool ans=(dict.find(key)==dict.end());
        if(ans){
            return -1;
        }
        else{
            int f=dict[key].first;
            int val=dict[key].second->second;
            freq[f].erase(dict[key].second);
            if(freq[f].size()==0){
                freq.erase(f);
                if(f==minFreq){
                    minFreq++;
                }
            }
            freq[f+1].push_back({key,val});
            auto it=freq[f+1].end();
            --it;
            dict[key]={f+1,it};
            return dict[key].second->second;
        }
    }
    
    void put(int key, int value) {
        if(cap<=0)return;
        if(size<cap){
            if(dict.find(key)==dict.end()){
                size++;
                freq[1].push_back({key,value});
                minFreq=1;
                auto it=freq[1].end();
                --it;
                dict[key]={1,it};
            }
            else{
                int f=dict[key].first;
                freq[f].erase(dict[key].second);
                if(freq[f].size()==0){
                    freq.erase(f);
                    if(minFreq==f){
                        minFreq++;
                    }
                }
                freq[f+1].push_back({key,value});
                auto it=freq[f+1].end();
                --it;
                dict[key]={f+1,it};
            }
        }
        else{
            if(dict.find(key)==dict.end()){
                dict.erase(freq[minFreq].front().first);
                freq[minFreq].pop_front();
                if(freq[minFreq].size()==0){
                    freq.erase(minFreq);
                }
                freq[1].push_back({key,value});
                minFreq=1;
                auto it=freq[1].end();
                --it;
                dict[key]={1,it};
            }
            else{
                int f=dict[key].first;
                freq[f].erase(dict[key].second);
                if(freq[f].size()==0){
                    freq.erase(f);
                    if(minFreq==f){
                        minFreq++;
                    }
                }
                freq[f+1].push_back({key,value});
                auto it=freq[f+1].end();
                --it;
                dict[key]={f+1,it};
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */