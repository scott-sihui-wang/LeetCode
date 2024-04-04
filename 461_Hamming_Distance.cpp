class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt=0;
        while(x>0 || y>0){
            cnt+=abs((x%2)-(y%2));
            x=x/2;
            y=y/2;
        }
        return cnt;
    }
};