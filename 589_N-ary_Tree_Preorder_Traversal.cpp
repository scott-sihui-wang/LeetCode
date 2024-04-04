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
    void preOrder(Node* root, vector<int>& sol){
        if(root==NULL){
            return;
        }
        else{
            sol.push_back(root->val);
            for(int i=0;i<root->children.size();i++){
                preOrder(root->children[i],sol);
            }
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> sol;
        preOrder(root,sol);
        return sol;
    }
};