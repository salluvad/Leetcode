class Solution {
public:
    //Since, the input is a BST, the right-most node in the tree is the maximum value present in the tree. So we first recursively go to the right-most node of the tree then process that node then go left.
    int curr_sum;
    void traverse(TreeNode* node){
        // Go right
        if(node->right) traverse(node->right);
        
        // Process node, add curr value to the right most node recursively
        curr_sum+=node->val;
        node->val=curr_sum;
        
        // Go left
        if(node->left) traverse(node->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        // if root is null return root
        if(!root) return root;
        
        // curr will store the sum of node-values higher than current node
        curr_sum=0;
        traverse(root);
        return root;
    }
};
