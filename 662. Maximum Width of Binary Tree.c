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
    vector<int> maxi ;
    vector<int> mini ;

    void traversal(TreeNode* root , int side ,  int level ){
        if(root==NULL){
            return ;
        }

        if(side>maxi){
            maxi = side ;
        }
        if(side<mini){
            mini = side ;
        }

        traversal( root->left , 2*side+1  , level+1 );
        traversal( root->right , 2*side+2 , level+1 ); 
    }

    int widthOfBinaryTree(TreeNode* root) {
  
    
        traversal(root,0,0) ;
        int ans = maxi - mini  ;
        return(ans) ;
    }
};