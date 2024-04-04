class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len=wordList.size();
        bool vis[len];
        unordered_map<string,int> dict;
        for(int i=0;i<len;i++){
            dict[wordList[i]]=i;
            vis[i]=false;
        }
        if(dict.find(endWord)==dict.end()){
            return 0;
        }
        int cnt=1;
        string s[5000];
        s[0]=beginWord;
        int left=0;
        int right=1;
        int prev_left;
        unordered_map<string,int>::iterator iter=dict.find(beginWord);
        if(iter!=dict.end()){
            vis[iter->second]=true;
        }
        bool reachable=false;
        while(left<right){
            ++cnt;
            prev_left=left;
            left=right;
            for(int i=prev_left;i<left;i++){
                int len_s=s[i].length();
                for(int j=0;j<len_s;j++){
                    for(int k=0;k<26;k++){
                        if('a'+k!=s[i][j]){
                            string tmp=s[i];
                            tmp[j]='a'+k;
                            iter=dict.find(tmp);
                            if(iter!=dict.end() && vis[iter->second]==false){
                                vis[iter->second]=true;
                                s[right++]=tmp;
                                if(tmp==endWord){
                                    reachable=true;
                                    break;
                                }
                            }
                        }
                    }
                    if(reachable)break;
                }
                if(reachable)break;
            }
            if(reachable)break;
        }
        if(reachable){
            return cnt;
        }
        else{
            return 0;
        }
    }
};