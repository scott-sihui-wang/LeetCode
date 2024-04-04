class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int num_words=words.size();
        int len=s.length();
        int cnt=num_words;
        bool vis[num_words];
        for(int i=0;i<num_words;i++){
            if(words[i].length()>s.length()){
                vis[i]=true;
                cnt--;
            }
            else{
                vis[i]=false;
            }
        }
        for(int i=0;i<len;i++){
            for(int j=0;j<num_words;j++){
                if(vis[j]==false && i<words[j].length() && s[i]!=words[j][i]){
                    vis[j]=true;
                    cnt--;
                }
            }
        }
        return cnt;
    }
};