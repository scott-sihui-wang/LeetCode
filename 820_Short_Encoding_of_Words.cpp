class Solution {
public:
    struct TrieNode{
        TrieNode *next[26];
        bool isLeaf;
        int len;
        TrieNode(){
            for(int i=0;i<26;i++){
                next[i]=nullptr;
            }
            isLeaf=true;
            len=0;
        }
    };
    void sum(TrieNode *node, int& ans){
        if(node->isLeaf){
            ans+=node->len;
            ans++;
        }
        else{
            for(int i=0;i<26;i++){
                if(node->next[i]!=nullptr){
                    sum(node->next[i],ans);
                }
            }
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0;
        TrieNode *root=new TrieNode();
        for(int i=0;i<words.size();i++){
            TrieNode *ptr=root;
            for(int j=words[i].size()-1;j>=0;j--){
                if(ptr->next[words[i][j]-'a']==nullptr){
                    ptr->next[words[i][j]-'a']=new TrieNode();
                    ptr->isLeaf=false;
                }
                ptr=ptr->next[words[i][j]-'a'];
            }
            ptr->len=words[i].size();
        }
        sum(root,ans);
        return ans;  
    }
};