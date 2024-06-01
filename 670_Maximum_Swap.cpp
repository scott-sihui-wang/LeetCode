class Solution {
public:
    int maximumSwap(int num) {
        if(num==0)return 0;
        vector<int> digits;
        while(num!=0){
            digits.push_back(num%10);
            num=num/10;
        }
        reverse(digits.begin(),digits.end());
        int n=digits.size();
        for(int i=0;i<n-1;i++){
            int M_num=digits[i],M_digit=i;
            for(int j=i+1;j<n;j++){
                if(digits[j]>=M_num){
                    M_num=digits[j];
                    M_digit=j;
                }
            }
            if(digits[i]<M_num){
                digits[M_digit]=digits[i];
                digits[i]=M_num;
                break;
            }
        }
        int ans=0;
        for(int i=0;i<digits.size();i++){
            ans=ans*10+digits[i];
        }
        return ans;
    }
};