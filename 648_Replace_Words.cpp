class Solution {
public:
    struct TrieNode{
        TrieNode* next[26];
        bool isEnd;
        TrieNode(){
            for(int i=0;i<26;i++){
                next[i]=nullptr;
                isEnd=false;
            }
        }
    };
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode *root=new TrieNode();
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
        string ans("");
        int idx=0;
        while(idx<sentence.size()){
            TrieNode *ptr=root;
            string word("");
            bool matching=true;
            while(idx<sentence.size() && sentence[idx]!=' '){
                if(matching && ptr->isEnd==false && ptr->next[sentence[idx]-'a']!=nullptr){
                    ptr=ptr->next[sentence[idx]-'a'];
                    word+=sentence[idx];
                }
                else{
                    matching=false;
                    if(ptr->isEnd==false){
                        word+=sentence[idx];
                    }
                }
                idx++;
            }
            ans+=word;
            if(idx<sentence.size()){
                idx++;
                ans+=' ';
            }
        }
        return ans;
    }
};