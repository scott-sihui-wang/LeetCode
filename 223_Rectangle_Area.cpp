class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ans=0;
        ans+=(ax2-ax1)*(ay2-ay1);
        ans+=(bx2-bx1)*(by2-by1);
        int intersection=0;
        if(bx1<ax1 && by1<ay1 && bx2>ax1 && by2>ay1){
            intersection=(min(bx2,ax2)-ax1)*(min(ay2,by2)-ay1);
        }
        else if(bx1<ax1 && by1<ay2 && by1>=ay1 && bx2>ax1){
            intersection=(min(ay2,by2)-by1)*(min(ax2,bx2)-ax1);
        }
        else if(bx1<ax2 && bx1>=ax1 && by1<ay1 && by2>ay1){
            intersection=(min(ay2,by2)-ay1)*(min(ax2,bx2)-bx1);
        }
        else if(bx1>=ax1 && by1>=ay1 && bx1<ax2 && by1<ay2){
            intersection=(min(ay2,by2)-by1)*(min(ax2,bx2)-bx1);
        }
        ans-=intersection;
        return ans;
    }
};