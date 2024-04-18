/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct_aux(vector<vector<int>>& grid,vector<vector<int>>& prefix_matrix,int row_begin,int row_end,int col_begin,int col_end){
        int cnt=prefix_matrix[row_end][col_end]-prefix_matrix[row_end][col_begin]-prefix_matrix[row_begin][col_end]+prefix_matrix[row_begin][col_begin];
        if(cnt==0){
            return new Node(false,true);
        }
        else if(cnt==(row_end-row_begin)*(col_end-col_begin)){
            return new Node(true,true);
        }
        else{
            Node* TL=construct_aux(grid,prefix_matrix,row_begin,(row_begin+row_end)/2,col_begin,(col_begin+col_end)/2);
            Node* TR=construct_aux(grid,prefix_matrix,row_begin,(row_begin+row_end)/2,(col_begin+col_end)/2,col_end);
            Node* BL=construct_aux(grid,prefix_matrix,(row_begin+row_end)/2,row_end,col_begin,(col_begin+col_end)/2);
            Node* BR=construct_aux(grid,prefix_matrix,(row_begin+row_end)/2,row_end,(col_begin+col_end)/2,col_end);
            return new Node(false,false,TL,TR,BL,BR);
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        int len=grid.size();
        vector<vector<int>> prefix_matrix(len+1,vector<int>(len+1,0));
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                prefix_matrix[i][j]=prefix_matrix[i-1][j]+prefix_matrix[i][j-1]-prefix_matrix[i-1][j-1]+(grid[i-1][j-1]==1?1:0);
            }
        }
        return construct_aux(grid,prefix_matrix,0,len,0,len);
    }
};