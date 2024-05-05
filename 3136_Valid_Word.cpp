class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;
        int cnt_vowel=0,cnt_consonant=0;
        for(int i=0;i<word.size();i++){
            if(!((word[i]>='0' && word[i]<='9')||(word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z'))){
                return false;
            }
            if((word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z')){
                if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U'){
                    cnt_vowel++;
                }
                else{
                    cnt_consonant++;
                }
            }
        }
        return (cnt_vowel>=1 && cnt_consonant>=1);
    }
};