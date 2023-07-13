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
    
    /*void traversal(TreeNode* root , int level , int side ,  map<int,pair<int,int>> &mapi ){
        if(root==NULL){
            return ;
        }
        if(mapi.find(level)==mapi.end()){
            mapi[level]={side, root->val} ;
        }
        else{
            if (side>=mapi[level].first){
                mapi[level].first = side ;
                mapi[level].second = root->val ;
            }
        }

        traversal( root->left , level + 1 , side - 1, mapi );
        traversal( root->right , level + 1 , side + 1, mapi ); 
    }*/

    void recursive_call(TreeNode* root,vector<int> &ans,int level){
        if(root==NULL){
            return ;
        }
        if(ans.size()==level) ans.push_back(root->val) ;
        recursive_call(root->right , ans , level+1 ) ;
        recursive_call(root->left , ans , level+1 ) ;
    }
    
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans ;
       recursive_call(root,ans,0) ;
       return(ans);  
       
       /* map<int,pair<int,int>> mapi ;
        traversal(root,0,0,mapi) ;
        vector<int> ans ;
        for (auto it : mapi){
            ans.push_back(it.second.second) ;
        } 
        return(ans) ;*/
    }
};