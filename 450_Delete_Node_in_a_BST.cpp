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
class Solution {
public:
    TreeNode* delete_node(TreeNode* node, TreeNode* parent, bool isRight){
        if(node==nullptr) return nullptr;
        if(node->right!=nullptr){
            if(node->right->left!=nullptr){
                TreeNode* left_ptr=node->right;
                TreeNode* left_most=left_ptr->left;
                while(left_most->left!=nullptr){
                    left_ptr=left_ptr->left;
                    left_most=left_most->left;
                }
                left_ptr->left=left_most->right;
                left_most->left=node->left;
                left_most->right=node->right;
                if(parent!=nullptr){
                    if(isRight){
                        parent->right=left_most;
                    }
                    else{
                        parent->left=left_most;
                    }
                }
                delete node;
                return left_most;
            }
            else{
                TreeNode* new_root=node->right;
                new_root->left=node->left;
                if(parent!=nullptr){
                    if(isRight){
                        parent->right=new_root;
                    }
                    else{
                        parent->left=new_root;
                    }
                }
                delete node;
                return new_root;
            }
        }
        else if(node->left!=nullptr){
            TreeNode* new_root=node->left;
            if(parent!=nullptr){
                if(isRight){
                    parent->right=new_root;
                }
                else{
                    parent->left=new_root;
                }
            }
            delete node;
            return new_root;
        }
        else{
            if(parent!=nullptr){
                if(isRight){
                    parent->right=nullptr;
                }
                else{
                    parent->left=nullptr;
                }
            }
            delete node;
            return nullptr;
        }
    }
    void traverse(TreeNode* root, TreeNode* parent, bool isRight, int key){
        if(root==nullptr)return ;
        if(root->val==key){
            delete_node(root,parent,isRight);
        }
        else if(root->val<key){
            traverse(root->right,root,true,key);
        }
        else{
            traverse(root->left,root,false,key);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)return nullptr;
        if(root->val==key){
            return delete_node(root,nullptr,false);
        }
        else{
            traverse(root,nullptr,false,key);
            return root;
        }
    }
};