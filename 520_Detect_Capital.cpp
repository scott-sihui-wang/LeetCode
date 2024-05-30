class Solution {
public:
    bool detectCapitalUse(string word) {
        bool AllCap=true,NonCap=true,NonCapFirst=true;
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z'){
                NonCap=false;
                if(i>0)NonCapFirst=false;
            }
            if(word[i]>='a' && word[i]<='z'){
                AllCap=false;
            }
        }
        return AllCap || NonCap || (word[0]>='A' && word[0]<='Z' && NonCapFirst);
    }
};