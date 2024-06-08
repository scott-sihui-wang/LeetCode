class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int sum=0;
        int i=1;
        while(sum<target){
            sum+=i;
            i++;
        }
        int diff=sum-target;
        if(diff%2==0){
            return i-1;
        }
        else{
            if((diff+i)%2==0){
                return i;
            }
            else{
                return i+1;
            }
        }
    }
};