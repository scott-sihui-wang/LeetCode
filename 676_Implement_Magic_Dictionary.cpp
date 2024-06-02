class MagicDictionary {
public:
    struct TrieNode{
        TrieNode *next[26];
        bool isEnd;
        TrieNode(){
            for(int i=0;i<26;i++){
                next[i]=nullptr;
                isEnd=false;
            }
        }
    };
    TrieNode *root;
    MagicDictionary() {
        root=new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i=0;i<dictionary.size();i++){
            TrieNode *ptr=root;
            for(int j=0;j<dictionary[i].size();j++){
                if(ptr->next[dictionary[i][j]-'a']==nullptr){
                    ptr->next[dictionary[i][j]-'a']=new TrieNode();
                }
                ptr=ptr->next[dictionary[i][j]-'a'];
            }
            ptr->isEnd=true;
        }
    }

    bool match(TrieNode *ptr, string searchWord){
        for(int i=0;i<searchWord.size();i++){
            if(ptr->next[searchWord[i]-'a']==nullptr){
                return false;
            }
            ptr=ptr->next[searchWord[i]-'a'];
        }
        return ptr->isEnd;
    }
    
    bool search(string searchWord) {
        TrieNode *ptr=root;
        int i=0;
        while(i<searchWord.size()){
            for(int j=0;j<26;j++){
                if(ptr->next[j]!=nullptr && (char)(j+'a')!=searchWord[i]){
                    bool res=match(ptr->next[j],searchWord.substr(i+1));
                    if(res)return true;
                }
            }
            if(ptr->next[searchWord[i]-'a']!=nullptr){
                ptr=ptr->next[searchWord[i]-'a'];
            }
            else{
                return false;
            }
            i++;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */