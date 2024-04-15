class WordDictionary {
public:
    struct TrieNode{
        TrieNode* next[26];
        bool isEnd;
        TrieNode(){
            for(int i=0;i<26;i++){
                next[i]=NULL;
            }
            isEnd=false;
        }
    };
    TrieNode* root;

    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* ptr=root;
        for(int i=0;i<word.size();i++){
            if(ptr->next[word[i]-'a']==NULL){
                ptr->next[word[i]-'a']=new TrieNode();
            }
            ptr=ptr->next[word[i]-'a'];
        }
        ptr->isEnd=true;
    }
    
    bool search_step(string word,TrieNode* ptr){
        if(word.size()>0 && word[0]!='.'){
            if(ptr->next[word[0]-'a']!=NULL){
                return search_step(word.substr(1),ptr->next[word[0]-'a']);
            }
            else{
                return false;
            }
        }
        else if(word.size()==0){
            return ptr->isEnd;
        }
        else{
            for(int i=0;i<26;i++){
                if(ptr->next[i]!=NULL){
                    if(search_step(word.substr(1),ptr->next[i])){
                        return true;
                    }
                }
            }
            return false;
        }
    }

    bool search(string word) {
        return search_step(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */