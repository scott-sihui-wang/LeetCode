class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int len=words.size();
        int i=0;
        for(;i<len;i++){
            int len_word=words[i].length();
            int left=0;
            int right=len_word-1;
            while(right-left>=1){
                if(words[i][left]!=words[i][right]){
                    break;
                }
                right--;
                left++;
            }
            if(right-left<=0){
                break;
            }
        }
        if(i<len){
            return words[i];
        }
        else{
            return string("");
        }
    }
};