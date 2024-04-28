class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num_5=0,num_10=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                num_5++;
            }
            else if(bills[i]==10){
                num_10++;
                if(num_5>0){
                    num_5--;
                }
                else{
                    return false;
                }
            }
            else if(bills[i]==20){
                if(num_5>0 && num_10>0){
                    num_5--;
                    num_10--;
                }
                else if(num_5>=3){
                    num_5-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};