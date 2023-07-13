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
    int ans = -1 ;

    void traversal(TreeNode* node , int k){
        if(node==NULL){
            return ;
        }
        traversal(node->left,k) ;
        
        if(count==k and ans==-1){
            ans = node->val ;
            return ;
        }
        
        count += 1 ;
        traversal(node->right,k) ;
    }

    int kthSmallest(TreeNode* root, int k) {
        traversal(root,k) ;

        return(ans) ;
    }
};