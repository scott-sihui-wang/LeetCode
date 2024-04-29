/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void DFS(Node* node, unordered_map<Node*,int>& dict, unordered_map<int,Node*>& dict_rev,int& idx){
        if(dict.find(node)==dict.end()){
            dict[node]=idx;
            dict_rev[idx]=node;
            idx++;
        }
        for(int i=0;i<node->neighbors.size();i++){
            if(dict.find(node->neighbors[i])==dict.end()){
                DFS(node->neighbors[i],dict,dict_rev,idx);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return nullptr;
        unordered_map<Node*,int>dict;
        unordered_map<int,Node*>dict_rev;
        int idx=0;
        DFS(node,dict,dict_rev,idx);
        Node *cpy[idx];
        for(int i=0;i<idx;i++){
            cpy[i]=new Node(dict_rev[i]->val);
        }
        for(int i=0;i<idx;i++){
            for(int j=0;j<dict_rev[i]->neighbors.size();j++){
                cpy[i]->neighbors.push_back(cpy[dict[dict_rev[i]->neighbors[j]]]);
            }
        }
        return cpy[0];
    }
};