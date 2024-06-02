class MapSum {
public:
    struct TrieNode{
        TrieNode *next[26];
        bool isEnd;
        int val;
        TrieNode(){
            for(int i=0;i<26;i++){
                next[i]=nullptr;
                isEnd=false;
                val=0;
            }
        }
    };
    TrieNode *root;
    MapSum() {
        root=new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *ptr=root;
        for(int i=0;i<key.size();i++){
            if(ptr->next[key[i]-'a']==nullptr){
                ptr->next[key[i]-'a']=new TrieNode();
            }
            ptr=ptr->next[key[i]-'a'];
        }
        ptr->isEnd=true;
        ptr->val=val;
    }

    void _sum(TrieNode* ptr, int& ans){
        if(ptr==nullptr)return;
        if(ptr!=nullptr && ptr->isEnd){
            ans+=ptr->val;
        }
        for(int i=0;i<26;i++){
            if(ptr->next[i]!=nullptr){
                _sum(ptr->next[i],ans);
            }
        }
    }
    
    int sum(string prefix) {
        int ans=0;
        TrieNode *ptr=root;
        for(int i=0;i<prefix.size();i++){
            if(ptr->next[prefix[i]-'a']==nullptr){
                return 0;
            }
            else{
                ptr=ptr->next[prefix[i]-'a'];
            }
        }
        _sum(ptr,ans);
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */