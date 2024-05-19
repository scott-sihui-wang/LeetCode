/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    ostringstream& s_serialize(TreeNode* root,ostringstream& out){
        if(root==nullptr){
            out<<"null ";
        }
        else{
            out<<root->val<<" ";
            s_serialize(root->left,out);
            s_serialize(root->right,out);
        }
        return out;
    }

    TreeNode* s_deserialize(istringstream& in){
        string node;
        in>>node;
        TreeNode* ptr;
        if(node=="null"){
            ptr=nullptr;
        }
        else{
            ptr=new TreeNode(stoi(node));
            ptr->left=s_deserialize(in);
            ptr->right=s_deserialize(in);
        }
        return ptr;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        s_serialize(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return s_deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;