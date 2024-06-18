class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double flow[query_row+1][query_row+1];
        memset(flow,0.0,sizeof(flow));
        flow[0][0]=poured;
        for(int i=1;i<=query_row;i++){
            for(int j=0;j<i;j++){
                double f=(flow[i-1][j]>1?(flow[i-1][j]-1)/2:0);
                flow[i][j]+=f;
                flow[i][j+1]+=f;
            }
        }
        return min(1.0,flow[query_row][query_glass]);
    }
};