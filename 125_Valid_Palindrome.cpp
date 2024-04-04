class Solution {
public:
    bool isAlphanumeric(char c){
        if(c>='0' && c<='9'){
            return true;
        }
        else if(c>='a' && c<='z'){
            return true;
        }
        else if(c>='A' && c<='Z'){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int left=0;
        int right=s.length()-1;
        if(right==0){
            return true;
        }
        bool outOfRange=false;
        while(right-left>=1){
            while(isAlphanumeric(s[left])==false){
                left++;
                if(left>s.length()-1){
                    outOfRange=true;
                    break;
                }
            }
            while(isAlphanumeric(s[right])==false){
                right--;
                if(right<0){
                    outOfRange=true;
                    break;
                }
            }
            if(outOfRange){
                return true;
            }
            bool equal;
            if(s[left]!=s[right]){
                if(s[left]>='A'&& s[left]<='Z' && s[right]>='a' && s[right]<='z' && s[left]+32==s[right]){
                    equal=true;
                }
                else if(s[left]>='a' && s[left]<='z' && s[right]>='A' && s[right]<='Z' && s[right]+32==s[left]){
                    equal=true;
                }
                else{
                    equal=false;
                }
            }
            else{
                equal=true;
            }
            if(equal==false){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};