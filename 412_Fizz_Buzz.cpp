class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>sol;
        for(int i=1;i<=n;i++){
            bool flag_3=(i%3==0);
            bool flag_5=(i%5==0);
            if(flag_3 && flag_5){
                sol.push_back(string("FizzBuzz"));
            }
            else if(flag_3){
                sol.push_back(string("Fizz"));
            }
            else if(flag_5){
                sol.push_back(string("Buzz"));
            }
            else{
                char digits[5];
                int idx=0;
                int num=i;
                while(num>0){
                    digits[idx++]=num%10+'0';
                    num=num/10;
                }
                string s(idx,'\0');
                for(int j=idx-1;j>=0;j--){
                    s[idx-1-j]=digits[j];
                }
                sol.push_back(s);
            }
        }
        return sol;
    }
};