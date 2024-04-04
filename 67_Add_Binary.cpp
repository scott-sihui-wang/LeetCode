class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        int overflow=0;
        char sol[10002];
        int cur=10001;
        sol[cur]='\0';
        cur=cur-1;
        while(i>=0 || j>=0|| overflow!=0){
            int val=0;
            if(i>=0){
                val+=a[i]-'0';
                i--;
            }
            if(j>=0){
                val+=b[j]-'0';
                j--;
            }
            if(overflow!=0){
                val+=overflow;
            }
            overflow=val/2;
            sol[cur]=val%2+'0';
            cur--;
        }
        return string(sol+cur+1);
    }
};