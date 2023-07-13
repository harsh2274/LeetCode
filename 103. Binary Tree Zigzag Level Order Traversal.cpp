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
    vector<vector<int>> vec ;
    int cur_lev = -1 ;
    

    void traversal(stack<pair< TreeNode* , int >> st){
        
        while(!st.empty()){
            TreeNode* root = st.top().first ; 
            int level  =  st.top().second ;
            st.pop() ;
            
            if (root==NULL){
                continue ;
            }
            
            if (cur_lev < level) {
                cur_lev = level ;
                vector<int> temp ;
                vec.push_back(temp) ;
            }

            vec[level].push_back(root->val) ;
        
            st.push({root->left,level+1}) ;
            st.push({root->right,level+1}) ;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<pair< TreeNode* , int >> st ;
        st.push({root,0}) ;
        traversal(st) ;
        int flag = 0 ; 
        int i = 0 ;
        for (auto it : vec){
            if(flag==0){ 
                reverse(vec[i].begin(),vec[i].end()) ;
                flag = 1 ;
            }
            else {
                flag = 0 ;
            }
            i++ ;
        }
        return(vec) ;
    }
};