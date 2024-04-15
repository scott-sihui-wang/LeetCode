/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    int sz,cur;
    vector<int> inOrder;
    void inOrderTraversal(TreeNode* ptr){
        if(ptr==nullptr)return;
        inOrderTraversal(ptr->left);
        inOrder.push_back(ptr->val);
        sz++;
        inOrderTraversal(ptr->right);
    }
    BSTIterator(TreeNode* root) {
        sz=0;
        cur=0;
        inOrderTraversal(root);
    }
    
    int next() {
        return inOrder[cur++];
    }
    
    bool hasNext() {
        return cur<=sz-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */