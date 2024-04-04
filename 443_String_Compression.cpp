class Solution {
public:
    int compress(vector<char>& chars) {
        int sol=0;
        int len=chars.size();
        int i=0;
        vector<char> res;
        while(i<len){
            int start=i;
            while(i+1<len && chars[i]==chars[i+1]){
                i++;
            }
            if(i+1-start==1){
                sol+=1;
                res.push_back(chars[i]);
            }
            else{
                sol+=1;
                res.push_back(chars[i]);
                int tmp=i+1-start;
                char c[4];
                int top=-1;
                while(tmp>0){
                    c[++top]=tmp%10+'0';
                    tmp=tmp/10;
                    sol+=1;
                }
                for(int j=top;j>=0;j--){
                    res.push_back(c[j]);
                }
            }
            i++;
        }
        chars=res;
        return sol;
    }
};