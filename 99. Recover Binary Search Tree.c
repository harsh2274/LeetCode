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
    vector<TreeNode*> vec2 ;
    
    void traversal(TreeNode* node){
        if(node==NULL){
            return ;
        }
        traversal(node->left) ;
        vec2.push_back(node) ;
        traversal(node->right) ;
    }

    void recoverTree(TreeNode* root) {
        traversal(root) ;
        TreeNode* temp1 = NULL ;
        TreeNode* temp2 = NULL ;
        TreeNode* temp3 = NULL ;

        for (int i = 1 ; i<vec2.size() ; i++){
            if(vec2[i]->val<vec2[i-1]->val){
                if(temp1==NULL){
                    temp1 = vec2[i] ;
                    temp2 = vec2[i-1] ;
                }
                else{
                    temp3 = vec2[i] ;  
                }
            }
        }

        if(temp3==NULL){
            int temp = temp1->val ;
            temp1->val = temp2->val ;
            temp2->val = temp ;
        }

        else{
            int temp = temp2->val ;
            temp2->val = temp3->val ;
            temp3->val = temp ;
        }
        return ;
    }
};