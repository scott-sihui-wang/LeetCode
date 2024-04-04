class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long cnt=0;
        while(total>=0){
            cnt+=total/cost2+1;
            total=total-cost1;
        }
        return cnt;
    }
};