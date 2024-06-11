class WordFilter {
public:
    struct TrieNode{
        unordered_map<int,TrieNode*> next;
        int last_id;
    };
    TrieNode *root=new TrieNode();
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            TrieNode *begin=root;
            for(int j=0;j<words[i].size();j++){
                TrieNode *ptr=begin;
                for(int k=j;k<words[i].size();k++){
                    if(ptr->next.find((words[i][k]-'a'+1)*27)==ptr->next.end()){
                        ptr->next[(words[i][k]-'a'+1)*27]=new TrieNode();
                    }
                    ptr=ptr->next[(words[i][k]-'a'+1)*27];
                    ptr->last_id=i;
                }
                ptr=begin;
                for(int k=words[i].size()-1-j;k>=0;k--){
                    if(ptr->next.find(words[i][k]-'a'+1)==ptr->next.end()){
                        ptr->next[words[i][k]-'a'+1]=new TrieNode();
                    }
                    ptr=ptr->next[words[i][k]-'a'+1];
                    ptr->last_id=i;
                }
                ptr=begin;
                if(ptr->next.find((words[i][j]-'a'+1)*27+(words[i][words[i].size()-1-j]-'a'+1))==ptr->next.end()){
                    ptr->next[(words[i][j]-'a'+1)*27+(words[i][words[i].size()-1-j]-'a'+1)]=new TrieNode();
                }
                ptr=ptr->next[(words[i][j]-'a'+1)*27+(words[i][words[i].size()-1-j]-'a'+1)];
                ptr->last_id=i;
                begin=ptr;
            }
        }
    }
    
    int f(string pref, string suff) {
        TrieNode *ptr=root;
        int i=0,j=suff.size()-1;
        while(i<pref.size() && j>=0){
            if(ptr->next.find((pref[i]-'a'+1)*27+(suff[j]-'a'+1))!=ptr->next.end()){
                ptr=ptr->next[(pref[i]-'a'+1)*27+(suff[j]-'a'+1)];
            }
            else{
                return -1;
            }
            i++;
            j--;
        }
        while(i<pref.size()){
            if(ptr->next.find((pref[i]-'a'+1)*27)!=ptr->next.end()){
                ptr=ptr->next[(pref[i]-'a'+1)*27];
            }
            else{
                return -1;
            }
            i++;
        }
        while(j>=0){
            if(ptr->next.find((suff[j]-'a'+1))!=ptr->next.end()){
                ptr=ptr->next[suff[j]-'a'+1];
            }
            else{
                return -1;
            }
            j--;
        }
        return ptr->last_id;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */