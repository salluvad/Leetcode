/*Start traversing the tree recursively and do work in Post Order.
For each call, caculate the height of the root node, and return it to previous calls.  
Simultaneously, in the Post Order of every node , Check for condition of balance as information of left and right subtree height is available.
If it is balanced , simply return height of current node and if not then return -1.
Whenever the subtree result is -1 , simply keep on returning -1.
  */
class Solution {
    int dfs_height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int lh = dfs_height(root->left);
        if(lh == -1) return -1;
        int rh = dfs_height(root->right);
        if(rh == -1) return -1 ;
        if(abs(lh-rh)>1){
            return -1 ;
        }
        
        
        return 1+max(lh,rh);
        
        
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return 1;
        return dfs_height(root)!=-1;
    }
};

