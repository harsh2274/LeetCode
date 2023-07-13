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

        sum = root->val + max(traversal(root->left,sum) , traversal(root->right,sum)) ; 
        if(sum<0){
            sum = 0 ;
        }
        return(sum) ;
    }
    
    void node_check(TreeNode* root ){
        if(root==NULL){
            return ;
        }
        int l_count = traversal(root->left , 0) ;
        int r_count = traversal(root->right , 0) ;

        if(l_count+r_count+root->val>maxi){
            maxi = l_count + r_count + root->val ;
        }
        
        
        node_check(root->left) ;
        node_check(root->right);    
    }

    int maxPathSum(TreeNode* root) {
        maxi = root->val ;
        node_check(root) ;
        return(maxi) ;
    }
};