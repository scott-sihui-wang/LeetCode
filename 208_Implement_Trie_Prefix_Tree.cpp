class Trie {
public:
    struct TrieNode{
        TrieNode* next[26];
        bool isEnd;
        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                next[i]=NULL;
            }
        }
    };
    TrieNode* t;
    Trie() {
        t=new TrieNode();
    }
    
    void insert(string word) {
        int len=word.length();
        TrieNode* ptr=t;
        for(int i=0;i<len;i++){
            if(ptr->next[word[i]-'a']==NULL){
                ptr->next[word[i]-'a']=new TrieNode();
            }
            ptr=ptr->next[word[i]-'a'];
        }
        ptr->isEnd=true;
    }
    
    bool search(string word) {
        int len=word.length();
        TrieNode* ptr=t;
        for(int i=0;i<len;i++){
            if(ptr->next[word[i]-'a']==NULL){
                return false;
            }
            ptr=ptr->next[word[i]-'a'];
        }
        return ptr->isEnd;
    }
    
    bool startsWith(string prefix) {
        int len=prefix.length();
        TrieNode* ptr=t;
        for(int i=0;i<len;i++){
            if(ptr->next[prefix[i]-'a']==NULL){
                return false;
            }
            ptr=ptr->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */