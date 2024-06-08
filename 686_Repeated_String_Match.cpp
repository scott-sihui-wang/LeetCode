class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int cnt=1;
        string a_dup=a;
        while(a_dup.size()<b.size()){
            a_dup+=a;
            cnt++;
        }
        for(int i=0;i<=a_dup.size()-b.size();i++){
            bool matched=true;
            for(int j=0;j<b.size();j++){
                if(a_dup[i+j]!=b[j]){
                    matched=false;
                }
            }
            if(matched)return cnt;
        }
        a_dup+=a;
        for(int i=0;i<a.size();i++){
            bool matched=true;
            for(int j=0;j<b.size();j++){
                if(a_dup[i+j]!=b[j]){
                    matched=false;
                }
            }
            if(matched)return cnt+1;
        }
        return -1;
    }
};