/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int maxi ;
    int mini ;
    TreeNode* ans ;

    void traversal(TreeNode* root){
        if (root==NULL){
            return ;
        }
        if(root->val==maxi || root->val==mini  ){
            ans = root ;
            return ;
        }
    
        if (root->right!=NULL && root->val < maxi  && root->left!=NULL && root->val > mini ){
            ans = root ;
            return ;
        }


        if (root->val>=maxi){
            traversal(root->left) ;
        }
        
        if(root->val<mini){
            traversal(root->right) ;
        }
    }



    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        maxi = max(p->val,q->val) ;
        mini = min(p->val,q->val) ;
        traversal(root);
        
        return(ans) ;     
    }
};