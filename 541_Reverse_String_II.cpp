class Solution {
public:
    string reverseStr(string s, int k) {
        if(k==1)return s;
        int bound;
        if(k%2==0){
            bound=(k-1)/2;
        }
        else{
            bound=k/2-1;
        }
        int len=s.length();
        int n=len/k/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<=bound;j++){
                char tmp=s[i*2*k+j];
                s[i*2*k+j]=s[(i*2+1)*k-1-j];
                s[(i*2+1)*k-1-j]=tmp;
            }
        }
        int residual=len-n*2*k;
        if(residual>=k){
            for(int j=0;j<=bound;j++){
                char tmp=s[2*n*k+j];
                s[2*n*k+j]=s[(2*n+1)*k-1-j];
                s[(2*n+1)*k-1-j]=tmp;
            }
        }
        else if(residual<k && residual>=2){
            if(residual%2==0){
                bound=(residual-1)/2;
            }
            else{
                bound=residual/2-1;
            }
            for(int j=0;j<=bound;j++){
                char tmp=s[2*n*k+j];
                s[2*n*k+j]=s[len-1-j];
                s[len-1-j]=tmp;
            }
        }
        return s;
    }
};