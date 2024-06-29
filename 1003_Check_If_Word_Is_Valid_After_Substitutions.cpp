class Solution {
public:
    bool isValid(string s) {
        int len=s.size();
        if(len%3!=0)return false;
        while(len>0){
            int i=0;
            bool contain=false;
            while(i<len-2){
                if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
                    s=s.substr(0,i)+s.substr(i+3);
                    len-=3;
                    contain=true;
                    break;
                }
                i++;
            }
            if(!contain)return false;
        }
        return true;
    }
};