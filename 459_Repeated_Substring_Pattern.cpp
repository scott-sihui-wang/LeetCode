class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.size();
        for(int i=1;i<=len/2;i++){
            if(len%i==0){
                int n=len/i-1;
                bool matched=true;
                for(int j=0;j<n;j++){
                    for(int k=0;k<i;k++){
                        if(s[k]!=s[(j+1)*i+k]){
                            matched=false;
                            break;
                        }
                    }
                    if(matched==false){
                        break;
                    }
                }
                if(matched)return true;
            }
        }
        return false;
    }
};