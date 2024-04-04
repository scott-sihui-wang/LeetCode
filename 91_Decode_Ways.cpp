class Solution {
public:
    int numDecodings(string s) {
        int len=s.size();
        int ways[len+1];
        memset(ways,0,sizeof(ways));
        ways[0]=1;
        for(int i=0;i<len;i++){
            if(s[i]=='0'){
                if(i==0)return 0;
                if(s[i-1]=='1'||s[i-1]=='2'){
                    ways[i+1]=ways[i-1];
                }
                else{
                    return 0;
                }
            }
            else{
                if(i>0 && (s[i-1]=='1'||(s[i-1]=='2' && s[i]<'7'))){
                    ways[i+1]=ways[i]+ways[i-1];
                }
                else{
                    ways[i+1]=ways[i];
                }
            }
        }
        return ways[len];
    }
};