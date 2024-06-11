class Solution {
public:
    int numberOfChild(int n, int k) {
        int m=k/(n-1);
        int l=k%(n-1);
        if(m%2==0){
            return k%(n-1);
        }
        else{
            return n-1-k%(n-1);
        }
    }
};