class Solution {
public:
    int solve(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        bool flag;
        unordered_map<int,bool> num_list;
        while(1){
            n=solve(n);
            if(n==1){
                flag=true;
                break;
            }
            else{
                unordered_map<int,bool>::iterator iter=num_list.find(n);
                if(iter!=num_list.end()){
                    flag=false;
                    break;
                }
                else{
                    num_list[n]=true;
                }
            }
        }
        return flag;
    }
};