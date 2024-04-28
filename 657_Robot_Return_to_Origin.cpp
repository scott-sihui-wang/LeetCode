class Solution {
public:
    bool judgeCircle(string moves) {
        int num_U=0,num_D=0,num_L=0,num_R=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                num_L++;
            }
            else if(moves[i]=='R'){
                num_R++;
            }
            else if(moves[i]=='U'){
                num_U++;
            }
            else{
                num_D++;
            }
        }
        return(num_U==num_D && num_L==num_R);
    }
};