/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > sol;
        if(root==NULL){
            return sol;
        }
        Node* node_list[10000];
        int left=0;
        int right=1;
        node_list[0]=root;
        int prev_left;
        while(left<right){
            vector<int> sol_level;
            for(int i=left;i<right;i++){
                sol_level.push_back(node_list[i]->val);
            }
            sol.push_back(sol_level);
            prev_left=left;
            left=right;
            for(int i=prev_left;i<left;i++){
                for(int j=0;j<node_list[i]->children.size();j++){
                    if(node_list[i]->children[j]!=NULL){
                        node_list[right++]=node_list[i]->children[j];
                    }
                }
            }            
        }
        return sol;
    }
};