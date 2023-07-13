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
    vector<int> vec ;
    void traversal(TreeNode* node){
        if(node==NULL){
            return ;
        }
        /*if(node->left==NULL && node->right!=NULL){
            cout << "NULL" << " " ;
        }*/
        
        //cout << node->val << " ";
        vec.push_back(node->val) ;
        traversal(node->left) ;
        traversal(node->right) ;
    }
     vector<int> preorderTraversal(TreeNode* root) {
        vector<int> temp ;
        traversal(root) ;
        return(vec) ;
    }
};
