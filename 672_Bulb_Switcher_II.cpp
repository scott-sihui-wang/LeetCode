class Solution {
public:
    int flipLights(int n, int presses) {
        if(presses==0)return 1;
        if(n>=3){
            if(presses==1){
                return 4;
            }
            else if(presses==2){
                return 7;
            }
            else{
                return 8;
            }
        }
        else if(n==2){
            return presses==1?3:4;
        }
        else{
            return 2;
        }
    }
};