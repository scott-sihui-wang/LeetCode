class Solution {
public:
    struct trieNode{
        trieNode *next[26];
        bool isEnd;
        trieNode(){
            for(int i=0;i<26;i++){
                next[i]=nullptr;
            }
            isEnd=false;
        }
    };
    void trieInsert(trieNode* root,vector<string>& words){
        for(int i=0;i<words.size();i++){
            trieNode* ptr=root;
            for(int j=0;j<words[i].size();j++){
                if(ptr->next[words[i][j]-'a']==nullptr){
                    ptr->next[words[i][j]-'a']=new trieNode();
                }
                ptr=ptr->next[words[i][j]-'a'];
            }
            ptr->isEnd=true;
        }
    }
    void search(trieNode* node,int x,int y,vector<vector<bool>>&visited,vector<vector<char>>& board,vector<string>& ans,string str){
        if(node->next[board[x][y]-'a']==nullptr){
            return;
        }
        else{
            node=node->next[board[x][y]-'a'];
            str.push_back(board[x][y]);
            visited[x][y]=true;
            if(node->isEnd){
                ans.push_back(str);
                node->isEnd=false;
            }
            if(x-1>=0 && visited[x-1][y]==false){
                search(node,x-1,y,visited,board,ans,str);
            }
            if(x+1<board.size() && visited[x+1][y]==false){
                search(node,x+1,y,visited,board,ans,str);
            }
            if(y-1>=0 && visited[x][y-1]==false){
                search(node,x,y-1,visited,board,ans,str);
            }
            if(y+1<board[0].size() && visited[x][y+1]==false){
                search(node,x,y+1,visited,board,ans,str);
            }
            str.pop_back();
            visited[x][y]=false;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        trieNode *root=new trieNode();
        trieInsert(root,words);
        vector<string> ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                search(root,i,j,visited,board,ans,"");
            }
        }
        return ans;
    }
};