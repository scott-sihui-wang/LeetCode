class Solution {
public:
    int isPrime(int freq){
        if(freq==2 || freq==3 || freq==5 || freq==7 || freq==11 || freq==13 || freq==17 || freq==19){
            return 1;
        }
        else{
            return 0;
        }
    }
    int countPrimeSetBits(int left, int right) {
        int bits[right+1];
        bits[0]=0;
        int prev_top=1;
        int top=1;
        int num=right;
        int cnt=0;
        while(num>0){
            num=num/2;
            for(int i=0;i<prev_top && top<=right;i++){
                bits[top]=bits[i]+1;
                if(top>=left && top<=right){
                    cnt+=isPrime(bits[top]);
                }
                top++;
            }
            prev_top=top;
        }
        return cnt;
    }
};