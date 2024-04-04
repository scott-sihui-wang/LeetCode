class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int divid_p=abs(dividend),divis_p=abs(divisor);
        unsigned int quot_p=0;
        bool sgn=((dividend>0 && divisor>0)||(dividend<0 && divisor<0));
        vector<int> bits;
        while(divis_p<=divid_p){
            int pow=0;
            unsigned int divis_q=divis_p;
            while(divis_q<divid_p){
                unsigned int tmp=divis_q<<1;
                if(tmp<=divid_p){
                    divis_q=tmp;
                    pow++;
                }
                else{
                    break;
                }
            }
            bits.push_back(pow);
            divid_p=divid_p-divis_q;
        }
        for(int i=0;i<bits.size();i++){
            quot_p+=pow(2,bits[i]);
        }
        if(sgn){
            if(quot_p<=INT_MAX){
                return (int)quot_p;
            }
            else{
                return INT_MAX;
            }
        }
        else{
            if(quot_p<=INT_MAX){
                return -(int)quot_p;
            }
            else{
                return INT_MIN;
            }
        }
    }
};