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
    int traversal(TreeNode* root, int sum ){
        if(root==NULL){
            return(sum);   
        }
        sum = 1 + max(traversal(root->left,sum) , traversal(root->right,sum));
        return(sum) ;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return(0);
        }
        return(traversal(root , 0 )) ;
    }
};