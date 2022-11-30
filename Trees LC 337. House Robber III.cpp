https://leetcode.com/problems/house-robber-iii/


class Solution {
public:
    // recursion + memo . we use a map to keep the previous values 
    unordered_map<TreeNode*,int>umap;
    int rob(TreeNode* root) {
        // there are two options , pick the node and not pick the node 
        // the get the max 
        if(root == NULL){
            return 0;
        }
        if(umap[root])return umap[root];
        //pick the node >> root->val + root->left->left +root->right->right
        
        int leftmax=0;
        int rightmax=0;
        
        if(root->left){
            leftmax = rob(root->left->left)+rob(root->left->right);
        }
        
         if(root->right){
            rightmax = rob(root->right->right)+rob(root->right->left);
        }
        
        return  umap[root]= max(root->val+leftmax+rightmax , rob(root->left)+rob(root->right));
    }
};
