class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int v1=0,v2=0;
        bool sgn=true;
        int i=0;
        while((v1<=red && v2<=blue)||(v1<=blue && v2<=red)){
            i++;
            if(sgn){
                v1+=i;
            }
            else{
                v2+=i;
            }
            sgn=!sgn;
        }
        return i-1;
    }
};