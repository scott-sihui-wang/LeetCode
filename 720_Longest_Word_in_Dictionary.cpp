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
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        TrieNode* root=new TrieNode();
        int max_len=0;
        string ans("");
        for(int i=0;i<words.size();i++){
            TrieNode* ptr=root;
            bool gen=true;
            for(int j=0;j<words[i].size();j++){
                if(ptr->next[words[i][j]-'a']==nullptr){
                    ptr->next[words[i][j]-'a']=new TrieNode();
                    if(j<words[i].size()-1)gen=false;
                }
                ptr=ptr->next[words[i][j]-'a'];
                if(j<words[i].size()-1 && ptr->isEnd==false)gen=false;
            }
            ptr->isEnd=true;
            if(gen){
                if(words[i].size()>max_len){
                    max_len=words[i].size();
                    ans=words[i];
                }
            }
        }
        return ans;
    }
};