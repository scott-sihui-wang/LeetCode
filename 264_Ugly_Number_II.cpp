class Solution {
public:
    int nthUglyNumber(int n) {
        int num[n];
        num[0]=1;
        int ptr2=0,ptr3=0,ptr5=0;
        for(int i=1;i<n;i++){
            int next_num;
            do{
                next_num=min(min(num[ptr2]*2,num[ptr3]*3),num[ptr5]*5);
                if(num[ptr2]*2==next_num){
                    ptr2++;
                }
                else if(num[ptr3]*3==next_num){
                    ptr3++;
                }
                else if(num[ptr5]*5==next_num){
                    ptr5++;
                }
            }while(next_num<=num[i-1]);
            num[i]=next_num;
        }
        return num[n-1];
    }
};