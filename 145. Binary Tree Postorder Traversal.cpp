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
        traversal(node->left) ;
        traversal(node->right) ;
        vec.push_back(node->val) ;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        traversal(root) ;
        return(vec) ;
    }
};