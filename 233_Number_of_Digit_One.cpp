class Solution {
public:
    int countDigitOne(int n) {
        int n1[9]={1,20,300,4000,50000,600000,7000000,80000000,900000000};
        int n2[9]={10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
        vector<int> digits;
        int m=n;
        while(m>0){
            digits.push_back(m%10);
            m=m/10;
        }
        int ans=0;
        for(int i=digits.size()-1;i>=1;i--){
            if(digits[i]==1){
                ans+=n1[i-1];
                ans+=n-n2[i-1]+1;
                n=n-n2[i-1];
            }
            else if(digits[i]>1){
                ans+=n1[i-1]*digits[i];
                ans+=n2[i-1];
                n=n-n2[i-1]*digits[i];
            }
        }
        if(digits.size()>=1 && digits[0]>=1){
            ans+=1;
        }
        return ans;
    }
};