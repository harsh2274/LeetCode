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
    int maxi = -99 ;
    int traversal(TreeNode* root, int sum ){
        if(root==NULL){
            return(sum);   
        }
        //left traversal
        sum = 1 + max(traversal(root->left,sum) , traversal(root->right,sum));
        return(sum) ;
    }
    
    void node_check(TreeNode* root ){
        if(root==NULL){
            return ;
        }
        int l_count = traversal(root->left , 0) ;
        int r_count = traversal(root->right , 0) ;
        
        if(l_count+r_count+1>maxi){
            maxi = l_count + r_count + 1 ;
        }
        
        node_check(root->left) ;
        node_check(root->right);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        node_check(root) ;
        return(maxi-1) ;
    }
};