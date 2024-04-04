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
    void postOrder(Node* root, vector<int>& sol){
        if(root==NULL){
            return;
        }
        else{
            for(int i=0;i<root->children.size();i++){
                postOrder(root->children[i],sol);
            }
            sol.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> sol;
        postOrder(root,sol);
        return sol;
    }
};