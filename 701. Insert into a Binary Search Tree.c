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

    void traversal(TreeNode* root, int data){
        if (root==NULL){
            return ;
        }
        if(root->val>data){
            TreeNode* temp = root->left ;
            if(temp!=NULL && temp->val<data){
                root->left = new TreeNode(data) ;
                root->left->left = temp ;
                root->left->right = NULL ;
                return ;
            }
            if(temp==NULL){
                root->left = new TreeNode(data) ;
                root->left->left = temp ;
                root->left->right = NULL ;
                return ;
            }
            traversal(temp,data);
        }

        else if(root->val<data){
            TreeNode* temp = root->right ;
            if(temp!=NULL && temp->val>data){
                root->right = new TreeNode(data) ;
                root->right->right = temp ;
                root->right->left = NULL ;
                return ;
            }
            if(temp==NULL){
                root->right = new TreeNode(data) ;
                root->right->right = temp ;
                root->right->left = NULL ;
                return ;
            }
            traversal(temp,data) ;
        }

    }
        

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        traversal(root,val);
        return(root);   

    }
};