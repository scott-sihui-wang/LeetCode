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
    void stream_serialize(TreeNode* root,ostringstream& out){
        if(root==nullptr){
            out<<"null ";
        }
        else{
            out<<root->val<<" ";
            stream_serialize(root->left,out);
            stream_serialize(root->right,out);
        }
    }

    TreeNode* stream_deserialize(istringstream& in){
        string node;
        in>>node;
        TreeNode* ptr;
        if(node=="null"){
            ptr=nullptr;
        }
        else{
            ptr=new TreeNode(stoi(node));
            ptr->left=stream_deserialize(in);
            ptr->right=stream_deserialize(in);
        }
        return ptr;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        stream_serialize(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return stream_deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));