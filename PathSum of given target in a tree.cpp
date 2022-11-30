class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL){
            return false;
        }
         // we reached the leaf node and we reached the target sum 
        if(targetSum==root->val and root->left==NULL and root->right==NULL){
            return true;
        }
        return hasPathSum(root->left , targetSum-root->val) or hasPathSum(root->right , targetSum-root->val) ;
        
    }
};
