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
    
    void parent_traversal(TreeNode* root , TreeNode* prev , map<TreeNode*,TreeNode*> &mapi, int level , int k , TreeNode* target , vector<int> &vec){
        if(root==NULL){
            return ;
        }
        if(root==target){
            return ;
        }

        cout << "root->val : " << root->val << " level: " << level << endl ;

        if(level==k){
            vec.push_back(root->val) ;
        }

        if(mapi[root]!=NULL && mapi[root]!=prev ){
            parent_traversal(mapi[root],root,mapi , level+1 , k , target , vec) ;
        }
        if(root->left!=NULL && root->left!=prev ){
            parent_traversal(root->left,root,mapi , level+1 , k , target , vec) ;
        }
        if(root->right!=NULL && root->right!=prev ){
            parent_traversal(root->right,root,mapi , level+1 , k , target , vec) ;
        }
    }

    void traversal_tree(TreeNode* root , map<TreeNode*,TreeNode*> &mapi){
        if(root==NULL){
            return ;
        }
        if (root->left!=NULL){
            mapi[root->left] = root ;
        }
        if (root->right!=NULL){
            mapi[root->right] = root ;
        }

        traversal_tree(root->left , mapi) ;
        traversal_tree(root->right , mapi) ;
    } 

    void traversal_after(TreeNode* root , int level , int k , vector<int> &vec){
        if(root==NULL){
            return ;
        }
        if (level==k){
            vec.push_back(root->val);
        }
        traversal_after(root->left , level+1 , k , vec) ;
        traversal_after(root->right , level+1 , k , vec) ;

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> mapi ;
        mapi[root] = NULL ;
        vector<int> vec ;
        traversal_tree(root , mapi) ;
        traversal_after(target , 0 , k , vec) ;
        if(mapi[target]!=NULL){
            parent_traversal(mapi[target] , target , mapi , 1 , k , target , vec) ;
        }
        return(vec) ;
    }
};