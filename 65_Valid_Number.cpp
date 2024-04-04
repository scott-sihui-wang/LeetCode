class Solution {
public:
    bool readSign(char c){
        return (c=='+' || c=='-');
    }
    bool readDigit(char c){
        return (c<='9' && c>='0');
    }
    bool readDot(char c){
        return c=='.';
    }
    bool readExp(char c){
        return (c=='e' || c=='E');
    }
    bool readAfterDot(string s,bool req_num){
        int len=s.size();
        if(len==0)return false;
        int i=0;
        if(req_num && !readDigit(s[i]))return false;
        while(i<len && readDigit(s[i])){
            i++;
        }
        if(i>=len){
            return true;
        }
        else if(readExp(s[i])){
            return readAfterExp(s.substr(i+1,len-i-1));
        }
        else{
            return false;
        }
    }
    bool readAfterExp(string s){
        int len=s.size();
        if(len==0)return false;
        int i=0;
        if(readSign(s[i])){
            i++;
        }
        if(i>=len)return false;
        while(i<len && readDigit(s[i])){
            i++;
        }
        if(i>=len){
            return true;
        }
        else{
            return false;
        }
    }
    bool isNumber(string s) {
        int len=s.size();
        int i=0;
        if(readSign(s[i])){
            i++;
        }
        if(i>=len)return false;
        if(readDot(s[i])){
            return readAfterDot(s.substr(i+1,len-i-1),true);
        }
        else if(readDigit(s[i])){
            while(i<len && readDigit(s[i])){
                i++;
            }
            if(i>=len){
                return true;
            }
            else if(readDot(s[i])){
                if(i==len-1){
                    return true;
                }
                else if(i<len-1 && readExp(s[i+1])){
                    return readAfterExp(s.substr(i+2,len-i-2));
                }
                else if(i<len-1 && readDigit(s[i+1])){
                    return readAfterDot(s.substr(i+1,len-i-1),false);
                }
                else{
                    return false;
                }
            }
            else if(readExp(s[i])){
                return readAfterExp(s.substr(i+1,len-i-1));
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
};