class Solution {
public:
    string clearDigits(string s) {
        bool containDigit=true;
        int i=0;
        while(i<s.size() && containDigit){
            while(i<s.size() && s[i]>='a' && s[i]<='z'){
                i++;
            }
            if(i==s.size()){
                containDigit=false;
            }
            else{
                s=s.substr(0,i-1)+s.substr(i+1);
                i=0;
            }
        }
        return s;
    }
};