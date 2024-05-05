class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int cnt1=(grid[0][0]=='B'?1:0)+(grid[0][1]=='B'?1:0)+(grid[1][0]=='B'?1:0)+(grid[1][1]=='B'?1:0);
        int cnt2=(grid[0][1]=='B'?1:0)+(grid[0][2]=='B'?1:0)+(grid[1][1]=='B'?1:0)+(grid[1][2]=='B'?1:0);
        int cnt3=(grid[1][0]=='B'?1:0)+(grid[1][1]=='B'?1:0)+(grid[2][0]=='B'?1:0)+(grid[2][1]=='B'?1:0);
        int cnt4=(grid[1][1]=='B'?1:0)+(grid[1][2]=='B'?1:0)+(grid[2][1]=='B'?1:0)+(grid[2][2]=='B'?1:0);
        return (cnt1!=2 || cnt2!=2 || cnt3!=2 || cnt4!=2);
    }
};