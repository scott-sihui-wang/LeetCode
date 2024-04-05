class Solution {
public:
    string makeGood(string s) {
        string ans=s;
        int i=0;
        while(i<(int)s.size()-1){
            if(abs((int)s[i]-(int)s[i+1])==32){
                s=s.substr(0,i)+s.substr(i+2,s.size()-i-2);
                if(i>0)i--;
            }
            else{
                i++;
            }
        }
        return s;
    }
};