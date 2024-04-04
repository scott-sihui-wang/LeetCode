class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len=gas.size();
        bool success;
        int i=0;
        while(i<len){
            int load=0;
            success=true;
            int j=0;
            for(;j<len;j++){
                load+=gas[(i+j)%len]-cost[(i+j)%len];
                if(load<0){
                    success=false;
                    break;
                }
            }
            if(success){
                return i;
            }
            else if(i+j+1>=len){
                return -1;
            }
            else{
                i=i+j+1;
            }
        }
        return -1;
    }
};