class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int len1=(p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
        int len2=(p1[0]-p3[0])*(p1[0]-p3[0])+(p1[1]-p3[1])*(p1[1]-p3[1]);
        int len3=(p2[0]-p3[0])*(p2[0]-p3[0])+(p2[1]-p3[1])*(p2[1]-p3[1]);
        if(len1==len2 && len3==len1+len2){
            if(p4[1]-p2[1]==p3[1]-p1[1] && p4[0]-p2[0]==p3[0]-p1[0]){
                return true;
            }
        }
        else if(len1==len3 && len2==len1+len3){
            if(p4[1]-p3[1]==p1[1]-p2[1] && p4[0]-p3[0]==p1[0]-p2[0]){
                return true;
            }
        }
        else if(len2==len3 && len1==len2+len3){
            if(p4[1]-p2[1]==p1[1]-p3[1] && p4[0]-p2[0]==p1[0]-p3[0]){
                return true;
            }
        }
        return false;
    }
};