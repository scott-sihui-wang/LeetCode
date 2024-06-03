class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        bool isOneBit=false;
        while(i<bits.size()){
            if(bits[i]==1){
                i+=2;
                isOneBit=false;
            }
            else if(bits[i]==0){
                i+=1;
                isOneBit=true;
            }
        }
        return isOneBit;
    }
};