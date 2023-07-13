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
class BSTIterator {
public:
    stack<TreeNode*> st ;
    BSTIterator(TreeNode* root) {
        while(root!=NULL){
            st.push(root);
            root = root->left ;
        }
    }
    
    int next() {
        TreeNode* temp = st.top() ;
        st.pop() ;
        TreeNode* temp2 = temp->right ;
        while(temp2!=NULL){
            st.push(temp2);
            temp2 = temp2->left ;
        }
        return(temp->val);

    }
    
    bool hasNext() {
        if(st.empty()){
            return(false);
        }
        return(true);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */