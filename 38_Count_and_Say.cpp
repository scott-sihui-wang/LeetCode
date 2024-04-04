class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return string("1");
        }
        else{
            string str("1");
            while(n>1){
                int len=str.length();
                string sol("");
                int i=0;
                while(i<len){
                    int start=i;
                    while(i<len-1 && str[i]==str[i+1]){
                        i++;
                    }
                    sol.append(1,i+1-start+'0');
                    sol.append(1,str[i]);
                    i++;
                }
                str=sol;
                n--;
            }
            return str;
        }
    }
};