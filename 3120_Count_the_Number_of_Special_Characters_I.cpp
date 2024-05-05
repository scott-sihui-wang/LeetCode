class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool l[26];
        memset(l,false,sizeof(l));
        unordered_set<char> s;
        int cnt=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z'){
                l[word[i]-'a']=true;
            }
        }
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z' && l[word[i]-'A']==true){
                if(s.find(word[i])==s.end()){
                    s.insert(word[i]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};