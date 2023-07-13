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
    
    int count = 1 ;
    long ans = -2147483649 ;

    void traversal(TreeNode* node ){
        if(node==NULL || count==0){
            return ;
        }
        traversal(node->left) ;
        
        if(ans>=node->val){
            count = 0 ;
            return ;
        }

        ans = node->val ;
        
        traversal(node->right) ;
    }

    bool isValidBST(TreeNode* root) {
        traversal(root) ;
        return(count) ; 
    }
};