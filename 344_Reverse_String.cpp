class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        int bound;
        if(len%2==0){
            bound=(len-1)/2;
        }
        else{
            bound=(len-2)/2;
        }
        for(int i=0;i<=bound;i++){
            char tmp=s[i];
            s[i]=s[len-1-i];
            s[len-1-i]=tmp;
        }
    }
};