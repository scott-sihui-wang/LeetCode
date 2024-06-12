class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>lower;
        map<char,int>upper;
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z'){
                lower[word[i]]=i;
            }
            if(word[i]>='A' && word[i]<='Z'){
                if(upper.find(word[i])==upper.end()){
                    upper[word[i]]=i;
                }
            }
        }
        int cnt=0;
        for(char c='a';c<='z';c++){
            if(lower.find(c)!=lower.end() && upper.find(c-32)!=upper.end() && lower[c]<upper[c-32]){
                cnt++;
            }
        }
        return cnt;
    }
};