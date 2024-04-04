class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int len=s.length();
        string result(len,' ');
        int idx=0;
        int ptr=0;
        while(idx<len){
            result[ptr++]=s[idx];
            idx=idx+2*(numRows-1);
        }
        if(numRows>2){
            for(int i=1;i<numRows-1;i++){
                idx=i;
                int cnt=0;
                while(idx<len){
                    result[ptr++]=s[idx];
                    if(cnt%2==0){
                        idx=idx+2*(numRows-i-1);
                    }
                    else{
                        idx=idx+2*i;
                    }
                    cnt++;
                }
            }
        }
        idx=numRows-1;
        while(idx<len){
            result[ptr++]=s[idx];
            idx=idx+2*(numRows-1);
        }
        return result;
    }
};