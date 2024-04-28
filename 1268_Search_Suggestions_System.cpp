class Solution {
public:
    struct TrieNode{
        TrieNode* next[26];
        bool isEnd;
        TrieNode(){
            for(int i=0;i<26;i++){
                next[i]=nullptr;
            }
            isEnd=false;
        }
    };

    struct Trie{
        TrieNode* root;
        Trie(){
            root=new TrieNode();
        }
        void store(string s){
            TrieNode* ptr=root;
            for(int i=0;i<s.size();i++){
                if(ptr->next[s[i]-'a']==nullptr){
                    ptr->next[s[i]-'a']=new TrieNode();
                }
                ptr=ptr->next[s[i]-'a'];
            }
            ptr->isEnd=true;
        }
    };

    void match(TrieNode* ptr,string& str,vector<string>& ans){
        if(ans.size()>=3)return;
        if(ptr->isEnd==true){
            ans.push_back(str);
        }
        for(int i=0;i<26;i++){
            if(ptr->next[i]!=nullptr){
                str+=string(1,'a'+i);
                match(ptr->next[i],str,ans);
                str=str.substr(0,str.size()-1);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        for(int i=0;i<products.size();i++){
            t.store(products[i]);
        }
        vector<vector<string>>ans;
        TrieNode* ptr=t.root;
        bool matched=true;
        string str("");
        for(int i=0;i<searchWord.size();i++){
            vector<string> s;
            if(ptr->next[searchWord[i]-'a']==nullptr||matched==false){
                matched=false;
            }
            else{
                ptr=ptr->next[searchWord[i]-'a'];
                str+=string(1,searchWord[i]);
                match(ptr,str,s);
            }
            ans.push_back(s);
        }
        return ans;
    }
};