class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int i=0;
        while(n<(1<<i) || n>(1<<(i+1))-1){
            i++;
        }
        return (1<<(i+1))-1-n;
    }
};