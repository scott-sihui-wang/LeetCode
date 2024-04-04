class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right)return left;
        int bits[31];
        int div=1;
        int base=2;
        for(int i=0;i<30;i++){
            if(right-left>=div+1 || (left%base)/div!=1 || (right%base)/div!=1 ){
                bits[i]=0;
            }
            else{
                bits[i]=1;
            }
            div*=2;
            if(i<29){
                base*=2;
            }
        }
        if(right-left>=div+1 || left/div!=1 || right/div!=1){
            bits[30]=0;
        }
        else{
            bits[30]=1;
        }
        int ans=0;
        for(int i=30;i>=0;i--){
            ans=ans*2+bits[i];
        }
        return ans;
    }
};