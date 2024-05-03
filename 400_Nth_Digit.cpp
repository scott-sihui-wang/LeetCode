class Solution {
public:
    int findNthDigit(int n) {
        int bound[10]={0,9,180,2700,36000,450000,5400000,63000000,720000000,INT_MAX};
        for(int i=2;i<9;i++){
            bound[i]+=bound[i-1];
        }
        int start[9]={0,9,99,999,9999,99999,999999,9999999,99999999};
        for(int i=0;i<9;i++){
            if(n>bound[i] && n<=bound[i+1]){
                int num=start[i]+(n-bound[i])/(i+1)+((n-bound[i])%(i+1)!=0?1:0);
                vector<int>digits;
                while(num>0){
                    digits.push_back(num%10);
                    num/=10;
                }
                if((n-bound[i])%(i+1)==0){
                    return digits[0];
                }
                else{
                    return digits[digits.size()-(n-bound[i])%(i+1)];
                }
            }
        }
        return -1;
    }
};